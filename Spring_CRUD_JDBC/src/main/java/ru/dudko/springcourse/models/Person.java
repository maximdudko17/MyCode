package ru.dudko.springcourse.models;

import jakarta.validation.constraints.*;

public class Person {
    private int id;
    @NotEmpty(message = "Name should not be empty")
    @Size(min = 10, max = 80, message = "Name should be between 10 and 80 chars")
    private String fullName;
    @Min(value = 1900, message = "Dont exist anymore")
    private int birthYear;

    public Person() {

    }

    public Person(int id, String fullName, int birthYear) {
        this.id = id;
        this.fullName = fullName;
        this.birthYear = birthYear;
    }

    public int getId() {
        return id;
    }

    public String getFullName() {
        return fullName;
    }

    public int getBirthYear() {
        return birthYear;
    }

    public void setFullName(String fullName) {
        this.fullName = fullName;
    }

    public void setBirthYear(int birthYear) {
        this.birthYear = birthYear;
    }

    public void setId(int id) {
        this.id = id;
    }
}