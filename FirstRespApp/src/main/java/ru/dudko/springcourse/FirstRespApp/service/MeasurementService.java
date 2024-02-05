package ru.dudko.springcourse.FirstRespApp.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import ru.dudko.springcourse.FirstRespApp.models.Measurement;
import ru.dudko.springcourse.FirstRespApp.models.Sensor;
import ru.dudko.springcourse.FirstRespApp.repositories.MeasurementRepository;
import ru.dudko.springcourse.FirstRespApp.util.SensorNotFoundException;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;

@Service
@Transactional(readOnly = true)
public class MeasurementService {
    private final MeasurementRepository measurementRepository;

    private final SensorService sensorService;

    @Autowired
    public MeasurementService(MeasurementRepository measurementRepository, SensorService sensorService) {
        this.measurementRepository = measurementRepository;
        this.sensorService = sensorService;
    }

    public List<Measurement> findAll(){
        return measurementRepository.findAll();
    }

    public Measurement findById(int id){
        Optional<Measurement> measurement = measurementRepository.findById(id);
        return measurement.orElse(null);
    }

    public List<Measurement>  find1000(){
        Optional<Measurement> measurement = measurementRepository.findTopByOrderByIdDesc();
        if(measurement.isPresent()){
            return measurementRepository.findByIdGreaterThan(measurement.get().getId() - 1000);
        }
        throw (new RuntimeException("NO SUCH MEASUREMENT"));
    }

    @Transactional
    public void save(Measurement measurement){
        Sensor sensor = sensorService.findByName(measurement.getSensor().getName())
                .orElseThrow(SensorNotFoundException::new);
        measurement.setSensor(sensor);
        enrichSensor(measurement);
        measurementRepository.save(measurement);
    }

    private void enrichSensor(Measurement measurement) {
        measurement.setCreatedAt(LocalDateTime.now());
    }


    @Transactional
    public void delete(Measurement measurement){
        measurementRepository.delete(measurement);
    }

}
