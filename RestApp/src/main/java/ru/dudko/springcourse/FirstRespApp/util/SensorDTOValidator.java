package ru.dudko.springcourse.FirstRespApp.util;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.validation.Errors;
import org.springframework.validation.Validator;
import ru.dudko.springcourse.FirstRespApp.dto.SensorDTO;
import ru.dudko.springcourse.FirstRespApp.models.Sensor;
import ru.dudko.springcourse.FirstRespApp.service.SensorService;

@Component
public class SensorDTOValidator implements Validator {
    private final SensorService sensorService;

    @Autowired
    public SensorDTOValidator(SensorService sensorService) {
        this.sensorService = sensorService;
    }

    @Override
    public boolean supports(Class<?> clazz) {
        return Sensor.class.equals(clazz);
    }

    @Override
    public void validate(Object target, Errors errors) {
        SensorDTO sensorDTO = (SensorDTO) target;

        if (sensorService.findByName(sensorDTO.getName()).isPresent()) {
            errors.rejectValue("name", "Taken", "This name is already in use");
        }
    }
}

