package ru.dudko.springcourse;

import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;
public class ClassicalMusic implements Music{

    private String[] arr = new String[]{"BAH", "BETH", "BRAM"};
    @Override
    public String getsong() {
        int ind = (int) (Math.random() * 3);
        return arr[ind];
    }

}
