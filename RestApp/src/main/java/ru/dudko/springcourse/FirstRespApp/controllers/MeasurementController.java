package ru.dudko.springcourse.FirstRespApp.controllers;

import jakarta.validation.Valid;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;
import ru.dudko.springcourse.FirstRespApp.DAO.MeasurementDAO;
import ru.dudko.springcourse.FirstRespApp.dto.MeasurementDTO;
import ru.dudko.springcourse.FirstRespApp.models.Measurement;
import ru.dudko.springcourse.FirstRespApp.service.MeasurementService;
import ru.dudko.springcourse.FirstRespApp.util.MeasurementErrorResponse;
import ru.dudko.springcourse.FirstRespApp.util.MeasurementNotCreatedException;
import ru.dudko.springcourse.FirstRespApp.util.SensorNotFoundException;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/measurements")
public class MeasurementController {
    private final MeasurementService measurementService;

    private final ModelMapper modelMapper;

    private final MeasurementDAO measurementDAO;

    @Autowired
    public MeasurementController(MeasurementService measurementService, ModelMapper modelMapper, MeasurementDAO measurementDAO) {
        this.measurementService = measurementService;
        this.modelMapper = modelMapper;
        this.measurementDAO = measurementDAO;
    }

    @RequestMapping(method=RequestMethod.GET)
    public List<MeasurementDTO> getAllMeasurements(){
        return measurementService.findAll().stream().map(this::toMeasurementDTO)
                .collect(Collectors.toList());

    }

    @GetMapping("/count")
    public long getAllMeasurementsRaining(){
        return measurementService.findAll().stream().filter(Measurement::isRaining)
                .count();

    }

    @GetMapping("/{id}")
    public MeasurementDTO getMeasurement(@PathVariable("id") int id){
        return toMeasurementDTO(measurementService.findById(id)); //Into JSON
    }

    @PostMapping(
    value = "/registration", consumes = "application/json", produces = "application/json")
    public ResponseEntity<HttpStatus> registration(@RequestBody @Valid MeasurementDTO measurementDTO,
                                                   BindingResult bindingResult) {
        if(bindingResult.hasErrors()) {
            StringBuilder errorMsg = new StringBuilder();

            List<FieldError> errors = bindingResult.getFieldErrors();
            for (FieldError error : errors) {
                errorMsg.append(error.getField())
                        .append(" - ").append(error.getDefaultMessage())
                        .append(";");
            }
            throw new MeasurementNotCreatedException(errorMsg.toString());
        }

        measurementService.save(toMeasurement(measurementDTO));

        return ResponseEntity.ok(HttpStatus.OK);
    }

    @PostMapping(
            value = "/registration/list", consumes = "application/json", produces = "application/json")
    public ResponseEntity<HttpStatus> registration(@RequestBody @Valid List<MeasurementDTO> measurements,
                                                   BindingResult bindingResult) {
        if(bindingResult.hasErrors()) {
            StringBuilder errorMsg = new StringBuilder();

            List<FieldError> errors = bindingResult.getFieldErrors();
            for (FieldError error : errors) {
                errorMsg.append(error.getField())
                        .append(" - ").append(error.getDefaultMessage())
                        .append(";");
            }
            throw new MeasurementNotCreatedException(errorMsg.toString());
        }

        measurementDAO.testBatchUpdate(measurements);

        return ResponseEntity.ok(HttpStatus.OK);
    }

    @GetMapping("1000")
    public List<MeasurementDTO> getAllSensor(){
        return measurementService.find1000().stream().map(this::toMeasurementDTO)
                .collect(Collectors.toList());

    }


    @ExceptionHandler
    private ResponseEntity<MeasurementErrorResponse> handleException(MeasurementNotCreatedException e){
        MeasurementErrorResponse response = new MeasurementErrorResponse(
                "Wrong data",
                System.currentTimeMillis()
        );
        return  new ResponseEntity<>(response, HttpStatus.NOT_FOUND);
    }

    @ExceptionHandler
    private ResponseEntity<MeasurementErrorResponse> handleException(SensorNotFoundException e){
        MeasurementErrorResponse response = new MeasurementErrorResponse(
                "Sensor with this name wasn't found",
                System.currentTimeMillis()
        );
        return  new ResponseEntity<>(response, HttpStatus.NOT_FOUND);
    }


    private MeasurementDTO toMeasurementDTO(Measurement measurement){
        return modelMapper.map(measurement, MeasurementDTO.class);
    }

    private Measurement toMeasurement(MeasurementDTO measurementDTO){
        return modelMapper.map(measurementDTO, Measurement.class);
    }

}
