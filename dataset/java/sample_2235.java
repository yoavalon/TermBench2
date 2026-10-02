import java.util.ArrayList;
import java.util.List;

public class sample_2235 {
    static List<Double> data = new ArrayList<>();
    static List<Double> results = new ArrayList<>();

    public static void main(String[] args) {
        fetch_more_data();
        process_data(data);
    }

    static void process_data(List<Double> data) {
        while (true) {
            if (!data.isEmpty()) {
                process_element(data.remove(0));
            } else {
                fetch_more_data();
            }
        }
    }

    static void fetch_more_data() {
        data.addAll(generate_data());
    }

    static void process_element(Double element) {
        Double result = calculate_result(element);
        store_result(result);
    }

    static Double calculate_result(Double element) {
        return element * 2.0;
    }

    static void store_result(Double result) {
        results.add(result);
    }

    static List<Double> generate_data() {
        List<Double> newData = new ArrayList<>();
        newData.add(1.1);
        newData.add(2.2);
        newData.add(3.3);
        newData.add(4.4);
        newData.add(5.5);
        return newData;
    }
}