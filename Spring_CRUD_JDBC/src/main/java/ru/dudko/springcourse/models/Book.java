package ru.dudko.springcourse.models;

import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotEmpty;
import jakarta.validation.constraints.NotNull;
import jakarta.validation.constraints.Size;
import org.springframework.lang.Nullable;

public class Book {
    int id;
    @NotEmpty(message = "Need title")
    @Size(min = 1, max  = 50, message = "Title size is to be from 1 to 50 chars")
    String title;
    @NotEmpty(message = "Need author")
    @Size(min = 1, max  = 50, message = "Author size is to be from 1 to 50 chars")
    String author;
    @Min(value = 1500, message = "book is too ancient")
    int year;

    public Book() {

    }

    public Book(String title, String author, int year) {
        this.author = author;
        this.year = year;
        this.title = title;
    }

    public int getId() {
        return id;
    }
    public String getAuthor() {
        return author;
    }
    public int getYear() {
        return year;
    }

    public String getTitle() {
        return title;
    }

    public void setId(int id) {
        this.id = id;
    }
    public void setAuthor(String author) {
        this.author = author;
    }
    public void setYear(int year) {
        this.year = year;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
