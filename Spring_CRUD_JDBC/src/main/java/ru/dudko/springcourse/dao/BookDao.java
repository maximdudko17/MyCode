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
public class BookDao {
    private final JdbcTemplate jdbcTemplate;

    @Autowired
    public BookDao(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    //Список весь
    public List<Book> index() {
        return jdbcTemplate.query("SELECT * FROM Book", new BeanPropertyRowMapper<>(Book.class));

    }
    //Список пренадлежащий конкретному человеку
    public List<Book> showBooks(int id_person){
        return jdbcTemplate.query("SELECT * FROM Book WHERE id_person = ?", new Object[]{id_person}, new BeanPropertyRowMapper<>(Book.class));
    }
    // Владелец книги
    public Optional<Person> getBookOwner(int id){
        return jdbcTemplate.query("SELECT Person.* FROM Book JOIN Person ON Book.id_person = Person.id " +
                "WHERE Book.id = ?", new Object[]{id}, new BeanPropertyRowMapper<>(Person.class))
                .stream().findAny();
    }
    // Вернуть книгу по айди
    public Book show(int id) {
        return jdbcTemplate.query("SELECT * FROM Book WHERE id=?", new Object[]{id}, new BeanPropertyRowMapper<>(Book.class))
                .stream().findAny().orElse(null);
    }



    public void save(Book book) {
        jdbcTemplate.update("INSERT INTO Book(title, author, year) VALUES( ?, ?, ?)", book.getTitle(),
                book.getAuthor(), book.getYear());
    }

    public void update(int id, Book updatedBook) {
        jdbcTemplate.update("UPDATE Book SET title=?, author=?, year=? WHERE id=?",
                updatedBook.getTitle(), updatedBook.getAuthor(), updatedBook.getYear(), id);
    }
    // Освободить
    public void free(int id) {
        jdbcTemplate.update("UPDATE Book SET id_person = null WHERE id=?", id);
    }
    public void delete(int id) {
        jdbcTemplate.update("DELETE FROM Book WHERE id=?", id);
    }
    // Человек берет книгу
    public void takeABook(int id_person, int id) {
        jdbcTemplate.update("UPDATE Book SET id_person = ? WHERE id=?", id_person, id);
    }
}