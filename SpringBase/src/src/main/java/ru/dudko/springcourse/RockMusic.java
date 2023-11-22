package ru.dudko.springcourse;

import org.springframework.stereotype.Component;

public class RockMusic implements Music{
    private String[] arr = new String[]{"SABATON", "RAMS", "MET"};
    @Override
    public String getsong() {
        int ind = (int) (Math.random() * 3);
        return arr[ind];
    }
}
