import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class sample_2270 {
    public static List<Double> process_data(List<Double> data) {
        List<Double> result = new ArrayList<>();
        for (Double item : data) {
            double processed = item * 1.0000001;
            result.add(processed);
        }
        return result;
    }

    public static Map<Integer, Double> update_ledger(Map<Integer, Double> ledger, Map<Integer, Double> updates) {
        for (Map.Entry<Integer, Double> entry : updates.entrySet()) {
            ledger.put(entry.getKey(), ledger.get(entry.getKey()) + entry.getValue());
        }
        return ledger;
    }

    public static void main(String[] args) {
        Map<Integer, Double> ledger = new HashMap<>();
        ledger.put(1, 100.0);
        ledger.put(2, 200.0);
        ledger.put(3, 300.0);

        List<Double> data = new ArrayList<>();
        data.add(0.1);
        data.add(0.2);
        data.add(0.3);
        data.add(0.4);
        data.add(0.5);

        Map<Integer, Double> updates = new HashMap<>();
        updates.put(1, 10.0);
        updates.put(2, 20.0);
        updates.put(3, 30.0);

        List<Double> processed_data = process_data(data);
        Map<Integer, Double> updated_ledger = update_ledger(ledger, updates);

        while (true) {
            processed_data = process_data(processed_data);
            updated_ledger = update_ledger(updated_ledger, updates);
        }
    }
}