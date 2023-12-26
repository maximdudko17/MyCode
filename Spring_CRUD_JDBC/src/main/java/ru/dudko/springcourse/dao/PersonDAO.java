package ru.dudko.springcourse.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;
import ru.dudko.springcourse.models.Book;
import ru.dudko.springcourse.models.Person;

import java.util.List;
import java.util.Optional;

@Component
public class PersonDAO {
    private final JdbcTemplate jdbcTemplate;

    @Autowired
    public PersonDAO(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    public List<Person> index() {
        return jdbcTemplate.query("SELECT * FROM Person", new BeanPropertyRowMapper<>(Person.class));

    }

    public Optional<Person> showOpt(int id) {
       return jdbcTemplate.query("SELECT * FROM Person WHERE id=?", new Object[]{id}, new BeanPropertyRowMapper<>(Person.class))
               .stream().findAny();
    }

    public Optional<Person> getByFullName(String fullName) {
        return jdbcTemplate.query("SELECT * FROM Person WHERE fullName=?", new Object[]{fullName}, new BeanPropertyRowMapper<>(Person.class))
                .stream().findAny();
    }

    public Person show(int id) {
        return jdbcTemplate.query("SELECT * FROM Person WHERE id=?", new Object[]{id}, new BeanPropertyRowMapper<>(Person.class))
                .stream().findAny().orElse(null);
    }

    public void save(Person person) {
        jdbcTemplate.update("INSERT INTO PERSON(fullName, birthYear) VALUES(?,?)", person.getFullName(),
                person.getBirthYear());
    }



    public void update(int id, Person updatedPerson) {
        jdbcTemplate.update("UPDATE Person SET fullName=?, birthYear=? WHERE id=?", updatedPerson.getFullName(),
                updatedPerson.getBirthYear(), id);
    }



    public void delete(int id) {
      jdbcTemplate.update("DELETE FROM Person WHERE id=?", id);
    }


}