package ru.dudko.springcourse.controllers;

import jakarta.validation.Valid;
import org.hibernate.sql.ast.tree.expression.Collation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;
import ru.dudko.springcourse.models.Book;
import ru.dudko.springcourse.models.Person;
import ru.dudko.springcourse.service.BookService;
import ru.dudko.springcourse.service.PeopleService;

import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Optional;

@Controller
@RequestMapping("/books")
public class BookController {
    private final BookService bookService;
    private final PeopleService peopleService;

    @Autowired
    public BookController(PeopleService peopleService, BookService bookService) {
        this.peopleService = peopleService;
        this.bookService = bookService;
    }


    @GetMapping()
    public String index(Model model, @RequestParam(value = "page", required = false) Integer page,
                        @RequestParam(value = "books_per_page", required = false) Integer books_per_page,
                        @RequestParam(value = "sort_by_year", required = false) boolean sort_by_year) {
        List<Book> books;
        if(page == null || books_per_page == null){
            books = bookService.findAll();
        }
        else {
            books = bookService.findAll(PageRequest.of(page, books_per_page)).getContent();
        }
        if(sort_by_year) Collections.sort(books);
        model.addAttribute("books", books);

        return "books/index";
    }

    @GetMapping("/{id}")
    public String show(@PathVariable("id") int id, Model model, @ModelAttribute("person")  Person person) {
        Book book = bookService.findOne(id);
        model.addAttribute("book", book);

        Optional<Person> owner = Optional.empty();

        if(book.getOwner() == null){
            model.addAttribute("people", peopleService.findAll());
            model.addAttribute("owner", owner);
        }
        else{
            owner = peopleService.findOne(book.getOwner().getId());
            model.addAttribute("owner", owner);
        }

        return "books/show";
    }

    @GetMapping("/new")
    public String newBook(@ModelAttribute("book") Book book) {
        return "books/new";
    }

    @GetMapping("/search")
    public String searchBook(Model model, @RequestParam(value = "startingWith", required = false) String startingWith) {
        model.addAttribute("book", bookService.findByNameStartingWith(startingWith));
        model.addAttribute("startingWith", startingWith);
        return "books/search";
    }

    @PostMapping()
    public String create(@ModelAttribute("book") @Valid Book book,
                         BindingResult bindingResult) {
        if(bindingResult.hasErrors()) return "books/new";
        bookService.save(book);
        return "redirect:/books";
    }

    @GetMapping("/{id}/edit")
    public String edit(Model model, @PathVariable("id") int id) {
        model.addAttribute("book", bookService.findOne(id));
        return "books/edit";
    }

    @PatchMapping("/{id}")
    public String update(@ModelAttribute("book") @Valid  Book book,
                         BindingResult bindingResult, @PathVariable("id") int id) {
        if(bindingResult.hasErrors()) return "books/edit";

        bookService.update(id, book);
        return "redirect:/books";
    }

    @PatchMapping("/{id}/free")
    public String free(@PathVariable("id") int id) {
        bookService.free(id);
        return "redirect:/books";
    }

    @PatchMapping("/{id}/takeABook")
    public String takeABook(@ModelAttribute Person person, @PathVariable("id") int id) {
        bookService.takeBook(id, person);
        return "redirect:/books";
    }

    @DeleteMapping("/{id}")
    public String delete(@PathVariable("id") int id) {
        bookService.delete(id);
        return "redirect:/books";
    }
}
