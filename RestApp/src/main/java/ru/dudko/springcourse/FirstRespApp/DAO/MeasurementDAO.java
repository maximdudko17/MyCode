package ru.dudko.springcourse.FirstRespApp.DAO;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BatchPreparedStatementSetter;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;
import ru.dudko.springcourse.FirstRespApp.dto.MeasurementDTO;
import ru.dudko.springcourse.FirstRespApp.models.Sensor;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.List;

@Component
public class MeasurementDAO {
    private final JdbcTemplate jdbcTemplate;

    @Autowired
    public MeasurementDAO(JdbcTemplate jdbcTemplate) {
        this.jdbcTemplate = jdbcTemplate;
    }

    private Sensor show(String name) {
        return jdbcTemplate.query("SELECT * FROM Sensor WHERE name=?", new Object[]{name}, new BeanPropertyRowMapper<>(Sensor.class))
                .stream().findAny().orElse(null);
    }

    public void testBatchUpdate(List<MeasurementDTO> measurements) {
        jdbcTemplate.batchUpdate("INSERT INTO measurement(sensor_id, value, raining, created_at) VALUES (?,?,?,?)",
                new BatchPreparedStatementSetter() {
                    @Override
                    public void setValues(PreparedStatement ps, int i) throws SQLException {
                        ps.setInt(1, show(measurements.get(i).getSensor().getName()).getId());
                        ps.setDouble(2, measurements.get(i).getValue());
                        ps.setBoolean(3, measurements.get(i).isRaining());
                        ps.setTimestamp(4, java.sql.Timestamp.valueOf(java.time.LocalDateTime.now()));
                    }

                    @Override
                    public int getBatchSize() {
                        return measurements.size();
                    }
                });
    }

}
