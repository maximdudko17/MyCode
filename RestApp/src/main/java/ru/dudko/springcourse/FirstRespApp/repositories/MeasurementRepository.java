package ru.dudko.springcourse.FirstRespApp.repositories;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import ru.dudko.springcourse.FirstRespApp.models.Measurement;

import java.util.List;
import java.util.Optional;

@Repository
public interface MeasurementRepository extends JpaRepository<Measurement, Integer> {
    Optional<Measurement> findTopByOrderByIdDesc();

    List<Measurement> findByIdGreaterThan(int id);

}
