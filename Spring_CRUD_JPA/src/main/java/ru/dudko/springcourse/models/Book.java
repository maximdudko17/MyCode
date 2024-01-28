package ru.dudko.springcourse.models;

import jakarta.persistence.*;
import jakarta.validation.constraints.Min;
import jakarta.validation.constraints.NotEmpty;
import jakarta.validation.constraints.Size;

import java.util.Date;

@Entity
@Table(name = "Book")
public class Book implements Comparable<Book>{
    @Id
    @Column(name = "id")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    int id;
    @NotEmpty(message = "Need title")
    @Size(min = 1, max  = 50, message = "Title size is to be from 1 to 50 chars")
    @Column(name = "name")
    private String name;
    @NotEmpty(message = "Need author")
    @Size(min = 1, max  = 50, message = "Author size is to be from 1 to 50 chars")
    @Column(name = "author")
    private String author;
    @Min(value = 1000, message = "book is too ancient")
    @Column(name = "year")
    private int year;

    @Column(name = "took_book_at")
    @Temporal(TemporalType.TIMESTAMP)
    private Date tookBookAt;


    @ManyToOne
    @JoinColumn(name = "person_id", referencedColumnName = "id")
    private Person owner;
    @Transient
    private boolean expired;

    public Book() {

    }

    public Book(String name, String author, int year, Date tookBookAt) {
        this.name = name;
        this.author = author;
        this.year = year;
        this.tookBookAt = tookBookAt;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAuthor() {
        return author;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public Person getOwner() {
        return owner;
    }

    public void setOwner(Person owner) {
        this.owner = owner;
    }

    public Date getTookBookAt() {
        return tookBookAt;
    }

    public void setTookBookAt(Date tookBookAt) {
        this.tookBookAt = tookBookAt;
    }

    public boolean isExpired() {
        return expired;
    }

    public void setExpired() {
        this.expired = new Date().getTime() - this.getTookBookAt().getTime() > 864000;
    }

    @Override
    public int compareTo(Book o) {
        return this.getYear() - o.getYear();
    }
}
