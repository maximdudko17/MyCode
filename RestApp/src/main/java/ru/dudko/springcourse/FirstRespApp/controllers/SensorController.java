package ru.dudko.springcourse.FirstRespApp.controllers;

import jakarta.validation.Valid;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;
import ru.dudko.springcourse.FirstRespApp.dto.SensorDTO;
import ru.dudko.springcourse.FirstRespApp.models.Sensor;
import ru.dudko.springcourse.FirstRespApp.service.SensorService;
import ru.dudko.springcourse.FirstRespApp.util.SensorDTOValidator;
import ru.dudko.springcourse.FirstRespApp.util.SensorErrorResponse;
import ru.dudko.springcourse.FirstRespApp.util.SensorNotRegisteredException;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/sensors")
public class SensorController {
    private final SensorService sensorService;

    private final ModelMapper modelMapper;

    private final SensorDTOValidator sensorDTOValidator;

    @Autowired
    public SensorController(SensorService sensorService, ModelMapper modelMapper, SensorDTOValidator sensorDTOValidator) {
        this.sensorService = sensorService;
        this.modelMapper = modelMapper;
        this.sensorDTOValidator = sensorDTOValidator;
    }

    @GetMapping()
    public List<SensorDTO> getAllSensor(){
        return sensorService.findAll().stream().map(this::toSensorDTO)
                .collect(Collectors.toList());

    }

    @GetMapping("/{id}")
    public SensorDTO getSensor(@PathVariable("id") int id){
        return toSensorDTO(sensorService.findById(id)); //Into JSON
    }

    @PostMapping("/registration")
    public ResponseEntity<HttpStatus> registration(@RequestBody @Valid SensorDTO sensorDTO,
                                      BindingResult bindingResult) {

        sensorDTOValidator.validate(sensorDTO, bindingResult);

        if(bindingResult.hasErrors()) {
            StringBuilder errorMsg = new StringBuilder();

            List<FieldError> errors = bindingResult.getFieldErrors();
            for (FieldError error : errors) {
                errorMsg.append(error.getField())
                        .append(" - ").append(error.getDefaultMessage())
                        .append(";");
            }
            throw new SensorNotRegisteredException(errorMsg.toString());
        }

        sensorService.save(toSensor(sensorDTO));

        return ResponseEntity.ok(HttpStatus.OK);
    }


    @ExceptionHandler
    private ResponseEntity<SensorErrorResponse> handleException(SensorNotRegisteredException e){
        SensorErrorResponse response = new SensorErrorResponse(
                "Wrong data",
                System.currentTimeMillis()
        );
        return  new ResponseEntity<>(response, HttpStatus.NOT_FOUND);
    }

    private SensorDTO toSensorDTO(Sensor sensor){
        return modelMapper.map(sensor, SensorDTO.class);
    }

    private Sensor toSensor(SensorDTO sensorDTO){
        return modelMapper.map(sensorDTO, Sensor.class);
    }


}
