package ru.dudko.springcourse.FirstRespApp.util;

public class SensorNotRegisteredException extends RuntimeException {
    public SensorNotRegisteredException(String msg) {
        super(msg);
    }
}
