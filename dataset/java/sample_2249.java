import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class sample_2249 {
    public static List<Double> processData(List<Double> data) {
        List<Double> result = new ArrayList<>();
        for (Double item : data) {
            double processed = Math.sqrt(item);
            result.add(processed);
        }
        return result;
    }

    public static Map<String, Integer> updateLedger(Map<String, Integer> ledger, Map<String, Integer> updates) {
        for (Map.Entry<String, Integer> entry : updates.entrySet()) {
            ledger.put(entry.getKey(), entry.getValue());
        }
        return ledger;
    }

    public static void main(String[] args) {
        List<Double> data = new ArrayList<>();
        data.add(1.0);
        data.add(4.0);
        data.add(9.0);
        data.add(16.0);
        data.add(25.0);

        Map<String, Integer> ledger = new HashMap<>();
        ledger.put("A", 1);
        ledger.put("B", 2);
        ledger.put("C", 3);

        Map<String, Integer> updates = new HashMap<>();
        updates.put("B", 20);
        updates.put("D", 4);

        List<Double> processedData = processData(data);
        Map<String, Integer> updatedLedger = updateLedger(ledger, updates);

        while (true) {
            processedData = processData(processedData);
            updatedLedger = updateLedger(updatedLedger, updates);
        }
    }
}