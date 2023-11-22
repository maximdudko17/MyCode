package ru.dudko.springcourse;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import java.util.*;

public class MusicPlayer {
    @Value("${musicPlayer.name}")
    private String name;
    @Value("${musicPlayer.volume}")
    private int volume;
   private Music music1;
    private Music music2;

    public String getName() {
        return name;
    }

    public int getVolume() {
        return volume;
    }
    public MusicPlayer(Music music1) {
        this.music1 = music1;
    }


    public void playMusic(){
        System.out.println(music1.getsong());
    }
}
