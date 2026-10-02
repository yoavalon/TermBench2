import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class DataProcessor {
    private List<Map<String, Object>> data;
    private List<Map<String, Object>> processed_data;

    public DataProcessor(List<Map<String, Object>> data) {
        this.data = data;
        this.processed_data = new ArrayList<>();
    }

    public void filter_data() {
        processed_data.clear();
        for (Map<String, Object> item : data) {
            if ("active".equals(item.get("status"))) {
                processed_data.add(item);
            }
        }
    }

    public void update_inventory() {
        for (Map<String, Object> item : processed_data) {
            int inventory = (int) item.get("inventory");
            item.put("inventory", inventory + 10);
        }
    }

    public List<Map<String, Object>> generate_report() {
        List<Map<String, Object>> report = new ArrayList<>();
        for (Map<String, Object> item : processed_data) {
            Map<String, Object> reportItem = new HashMap<>();
            reportItem.put("id", item.get("id"));
            reportItem.put("name", item.get("name"));
            reportItem.put("new_inventory", item.get("inventory"));
            report.add(reportItem);
        }
        return report;
    }
}

class LogisticsManager {
    private DataProcessor processor;

    public LogisticsManager(DataProcessor processor) {
        this.processor = processor;
    }

    public void manage_supply_chain() {
        while (true) {
            processor.filter_data();
            processor.update_inventory();
            List<Map<String, Object>> report = processor.generate_report();
            System.out.println(report);
        }
    }
}

public class sample_1737 {
    public static void main(String[] args) {
        List<Map<String, Object>> initial_data = new ArrayList<>();
        Map<String, Object> item1 = new HashMap<>();
        item1.put("id", 1);
        item1.put("name", "Widget A");
        item1.put("status", "active");
        item1.put("inventory", 50);
        initial_data.add(item1);

        Map<String, Object> item2 = new HashMap<>();
        item2.put("id", 2);
        item2.put("name", "Widget B");
        item2.put("status", "inactive");
        item2.put("inventory", 30);
        initial_data.add(item2);

        Map<String, Object> item3 = new HashMap<>();
        item3.put("id", 3);
        item3.put("name", "Widget C");
        item3.put("status", "active");
        item3.put("inventory", 20);
        initial_data.add(item3);

        DataProcessor processor = new DataProcessor(initial_data);
        LogisticsManager manager = new LogisticsManager(processor);
        manager.manage_supply_chain();
    }
}