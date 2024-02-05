package ru.dudko.springcourse.FirstRespApp.dto;

import jakarta.validation.constraints.Max;
import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotNull;
import ru.dudko.springcourse.FirstRespApp.models.Sensor;

public class MeasurementDTO {
    @Min(value = -100, message = "-100 is MIN")
    @Max(value = 100, message = "100 is MAX")
    private double value;

    private boolean raining;

    @NotNull
    private SensorDTO sensor;

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public boolean isRaining() {
        return raining;
    }

    public void setRaining(boolean raining) {
        this.raining = raining;
    }

    public SensorDTO getSensor() {
        return sensor;
    }

    public void setSensor(SensorDTO sensor) {
        this.sensor = sensor;
    }
}
