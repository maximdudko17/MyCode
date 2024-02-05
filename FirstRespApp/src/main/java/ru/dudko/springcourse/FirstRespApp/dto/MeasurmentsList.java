package ru.dudko.springcourse.FirstRespApp.dto;

import java.util.List;

public class MeasurmentsList {
    private List<MeasurementDTO> measurements;

    public MeasurmentsList(List<MeasurementDTO> measurements) {
        this.measurements = measurements;
    }

    public List<MeasurementDTO> getMeasurements() {
        return measurements;
    }

    public void setMeasurements(List<MeasurementDTO> measurements) {
        this.measurements = measurements;
    }
}
