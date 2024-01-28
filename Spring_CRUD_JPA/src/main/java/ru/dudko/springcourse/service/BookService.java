package ru.dudko.springcourse.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import ru.dudko.springcourse.models.Book;
import ru.dudko.springcourse.models.Person;
import ru.dudko.springcourse.repositories.BookRepository;

import java.util.Date;
import java.util.List;
import java.util.Optional;

@Service
@Transactional(readOnly = true)
public class BookService{
    private final BookRepository bookRepository;

    @Autowired
    public BookService( BookRepository bookRepository) {
        this.bookRepository = bookRepository;
    }

    public List<Book> findAll(){
        return bookRepository.findAll();
    }

    public Page<Book> findAll(Pageable pageable){
        return bookRepository.findAll(pageable);
    }
    
    public Book findOne(int id){
        Optional<Book> book = bookRepository.findById(id);
        return book.orElse(null);
    }

    public Optional<Book> findByNameStartingWith(String name){
        List<Book> books = bookRepository.findByNameStartingWith(name);
        if(books.isEmpty()) return Optional.empty();
        return Optional.ofNullable(books.get(0));
    }

    public List<Book> findPersonBooks(Person owner){
        return bookRepository.findByOwner(owner);
    }

    public void CheckExpiredAll(List<Book> books){
        for(Book book: books){
            book.setExpired();
        }
    }

    @Transactional
    public void save(Book book){
        bookRepository.save(book);
    }

    @Transactional
    public void update(int id, Book updatedBook){
        updatedBook.setId(id);
        bookRepository.save(updatedBook);
    }

    @Transactional
    public void delete(int id){
        bookRepository.deleteById(id);
    }

    @Transactional
    public void free(int id){
        if(bookRepository.findById(id).isPresent()){
            Book book = bookRepository.findById(id).get();
            book.setOwner(null);
            bookRepository.save(book);
        }
    }

    @Transactional
    public void takeBook(int id, Person person){
        if(bookRepository.findById(id).isPresent()){
            Book book = bookRepository.findById(id).get();
            book.setOwner(person);
            book.setTookBookAt(new Date());
            bookRepository.save(book);
        }
    }


}
