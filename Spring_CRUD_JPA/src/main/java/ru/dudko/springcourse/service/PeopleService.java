package ru.dudko.springcourse.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import ru.dudko.springcourse.models.Person;
import ru.dudko.springcourse.repositories.PeopleRepository;

import java.util.Date;
import java.util.List;
import java.util.Optional;

@Service
@Transactional(readOnly = true)
public class PeopleService {
    private final PeopleRepository peopleRepository;

    @Autowired
    public PeopleService(PeopleRepository peopleRepository) {
        this.peopleRepository = peopleRepository;
    }

    public List<Person> findAll(){
        return peopleRepository.findAll();
    }

    public Optional<Person> findOne(int id){
        return peopleRepository.findById(id);
    }

    @Transactional
    public void save(Person person){
        peopleRepository.save(person);
}

    @Transactional
    public void update(int id, Person updatedPerson){
        updatedPerson.setId(id);
        peopleRepository.save(updatedPerson);
    }


    @Transactional
    public void delete(int id){
        peopleRepository.deleteById(id);
    }

}
