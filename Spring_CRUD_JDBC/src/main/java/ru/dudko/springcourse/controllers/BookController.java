package ru.dudko.springcourse.controllers;

import jakarta.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;
import ru.dudko.springcourse.dao.BookDao;
import ru.dudko.springcourse.dao.PersonDAO;
import ru.dudko.springcourse.models.Book;
import ru.dudko.springcourse.models.Person;
import ru.dudko.springcourse.util.BookValidator;
import ru.dudko.springcourse.util.PersonValidator;

import java.util.Optional;

@Controller
@RequestMapping("/books")
public class BookController {
    private final BookDao bookDao;
    private final BookValidator bookValidator;
    private final PersonDAO personDAO;

    @Autowired
    public BookController(BookDao bookDao, BookValidator bookValidator, PersonDAO personDAO) {
        this.personDAO = personDAO;
        this.bookDao = bookDao;
        this.bookValidator = bookValidator;
    }


    @GetMapping()
    public String index(Model model) {
        model.addAttribute("books", bookDao.index());
        return "books/index";
    }

    @GetMapping("/{id}")
    public String show(@PathVariable("id") int id, Model model, @ModelAttribute("person")  Person person) {
        model.addAttribute("book", bookDao.show(id));

        Optional<Person> owner = bookDao.getBookOwner(id);
        model.addAttribute("owner", owner);

        if(!owner.isPresent()){
            model.addAttribute("people", personDAO.index());
        }

        return "books/show";
    }

    @GetMapping("/new")
    public String newBook(@ModelAttribute("book") Book book) {
        return "books/new";
    }

    @PostMapping()
    public String create(@ModelAttribute("book") @Valid Book book,
                         BindingResult bindingResult) {
        bookValidator.validate(book, bindingResult);

        if(bindingResult.hasErrors()) return "books/new";
        bookDao.save(book);
        return "redirect:/books";
    }

    @GetMapping("/{id}/edit")
    public String edit(Model model, @PathVariable("id") int id) {
        model.addAttribute("book", bookDao.show(id));
        return "books/edit";
    }

    @PatchMapping("/{id}")
    public String update(@ModelAttribute("book") @Valid  Book book,
                         BindingResult bindingResult, @PathVariable("id") int id) {
        bookValidator.validate(book, bindingResult);
        if(bindingResult.hasErrors()) return "book/edit";

        bookDao.update(id, book);
        return "redirect:/books";
    }

    @PatchMapping("/{id}/free")
    public String free(@PathVariable("id") int id) {
        bookDao.free(id);
        return "redirect:/books";
    }

    @PatchMapping("/{id}/takeABook")
    public String takeABook(@ModelAttribute Person person, @PathVariable("id") int id) {
        bookDao.takeABook(person.getId(), id);
        return "redirect:/books";
    }

    @DeleteMapping("/{id}")
    public String delete(@PathVariable("id") int id) {
        bookDao.delete(id);
        return "redirect:/books";
    }
}
