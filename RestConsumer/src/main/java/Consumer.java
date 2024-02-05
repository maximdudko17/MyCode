import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.json.JSONObject;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.client.RestTemplate;

import java.util.*;

public class Consumer {

    public static void main(String[] args) throws JsonProcessingException {
        RestTemplate restTemplate = new RestTemplate();
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);
        String urlSensor = "http://localhost:8080/sensors/registration";
        String urlMeasurementsCreateList = "http://localhost:8080/measurements/registration/list";
        String urlMeasurements = "http://localhost:8080/measurements";
        String urlMeasurements1000 = "http://localhost:8080/measurements/1000";
        ObjectMapper objectMapper = new ObjectMapper();

 //        !!!! CREATE NEW SENSOR !!!

        JSONObject jsonSensor = new JSONObject();
        String sensorName = "New3";
        jsonSensor.put("name", sensorName);

        HttpEntity<String> request =
                new HttpEntity<String>(jsonSensor.toString(), headers);

        String response =
                restTemplate.postForObject(urlSensor, request, String.class);

        JsonNode root = objectMapper.readTree(response);

        System.out.println(response);

        // !!!ADDING 1000 MEASUREMENTS TO THIS SERVER!!!

        double value;
        boolean raining;
        Random r = new Random();
        List<MeasurementDTO> measurementDTOList = new ArrayList<>();
        for(int i = 0; i < 1000; i++) {
            value = -100 + (100 + 100) * r.nextDouble();
            raining = r.nextBoolean();
            SensorDTO sensorDTO = new SensorDTO(sensorName);
            measurementDTOList.add(new MeasurementDTO(value, raining, sensorDTO));
        }

        System.out.println(Collections.unmodifiableList(measurementDTOList));

        String response1 =
                restTemplate.postForObject(urlMeasurementsCreateList,
                        measurementDTOList, String.class);

        System.out.println(response1);

         //GET THESE 1000 MEASUREMENTS

        ResponseEntity<MeasurementDTO[]> response2 =
                restTemplate.getForEntity(
                        urlMeasurements1000,
                        MeasurementDTO[].class);
        MeasurementDTO[] measurements = response2.getBody();

        System.out.println(Arrays.toString(measurements));

    }
}
