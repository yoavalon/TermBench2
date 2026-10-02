import java.util.HashMap;
import java.util.Map;

public class sample_1951 {
    public static double calculateTemperature(Map<String, Double> state, int precision) {
        double a = state.get("a");
        double b = state.get("b");
        double c = state.get("c");
        double temperature = (a + b + c) / 3;
        return Math.round(temperature * Math.pow(10, precision)) / Math.pow(10, precision);
    }

    public static Map<String, Double> simulateState(Map<String, Double> state, int precision) {
        double temp = calculateTemperature(state, precision);
        double pressure = Math.exp(temp);
        double volume = 1 / pressure;
        Map<String, Double> result = new HashMap<>();
        result.put("temperature", temp);
        result.put("pressure", pressure);
        result.put("volume", volume);
        return result;
    }

    public static void main(String[] args) {
        Map<String, Double> state = new HashMap<>();
        state.put("a", 298.15);
        state.put("b", 300.0);
        state.put("c", 295.0);
        int precision = 4;
        Map<String, Double> result = simulateState(state, precision);
        System.out.println(result);
    }
}