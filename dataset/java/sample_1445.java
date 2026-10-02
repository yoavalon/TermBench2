import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class sample_1445 {

    static class DataProcessor {
        List<Map<String, Object>> data;

        DataProcessor(List<Map<String, Object>> data) {
            this.data = data;
        }

        List<Map<String, Object>> process_data() {
            List<Map<String, Object>> transformed_data = new ArrayList<>();
            for (Map<String, Object> item : data) {
                if ("active".equals(item.get("status"))) {
                    transformed_data.add(modify_item(item));
                }
            }
            return transformed_data;
        }

        Map<String, Object> modify_item(Map<String, Object> item) {
            item.put("quantity", (Integer) item.get("quantity") * 1.1);
            item.put("cost", (Integer) item.get("cost") * 0.95);
            return item;
        }
    }

    static class DataMutator {
        DataProcessor processor;

        DataMutator(DataProcessor processor) {
            this.processor = processor;
        }

        List<Map<String, Object>> mutate_data() {
            List<Map<String, Object>> mutated_data = new ArrayList<>();
            for (Map<String, Object> item : processor.data) {
                if ("critical".equals(item.get("category"))) {
                    mutated_data.add(alter_item(item));
                }
            }
            return mutated_data;
        }

        Map<String, Object> alter_item(Map<String, Object> item) {
            item.put("priority", "high");
            item.put("reorder", true);
            return item;
        }
    }

    static class DataAnalyzer {
        DataMutator mutator;

        DataAnalyzer(DataMutator mutator) {
            this.mutator = mutator;
        }

        Map<String, Map<String, Object>> analyze_data() {
            Map<String, Map<String, Object>> analysis = new HashMap<>();
            for (Map<String, Object> item : mutator.mutated_data) {
                String region = (String) item.get("region");
                if (!analysis.containsKey(region)) {
                    analysis.put(region, new HashMap<String, Object>() {{
                        put("total_cost", 0);
                        put("item_count", 0);
                    }});
                }
                Map<String, Object> regionData = analysis.get(region);
                regionData.put("total_cost", (Integer) regionData.get("total_cost") + (Integer) item.get("cost"));
                regionData.put("item_count", (Integer) regionData.get("item_count") + 1);
            }
            return analysis;
        }
    }

    public static void main(String[] args) {
        List<Map<String, Object>> initial_data = new ArrayList<>();
        initial_data.add(new HashMap<String, Object>() {{
            put("status", "active");
            put("category", "critical");
            put("region", "north");
            put("quantity", 100);
            put("cost", 10);
        }});
        initial_data.add(new HashMap<String, Object>() {{
            put("status", "inactive");
            put("category", "standard");
            put("region", "south");
            put("quantity", 200);
            put("cost", 20);
        }});
        initial_data.add(new HashMap<String, Object>() {{
            put("status", "active");
            put("category", "critical");
            put("region", "east");
            put("quantity", 150);
            put("cost", 15);
        }});
        initial_data.add(new HashMap<String, Object>() {{
            put("status", "active");
            put("category", "standard");
            put("region", "west");
            put("quantity", 300);
            put("cost", 30);
        }});

        DataProcessor processor = new DataProcessor(initial_data);
        List<Map<String, Object>> processed_data = processor.process_data();
        DataMutator mutator = new DataMutator(processor);
        List<Map<String, Object>> mutated_data = mutator.mutate_data();
        DataAnalyzer analyzer = new DataAnalyzer(mutator);
        Map<String, Map<String, Object>> analysis = analyzer.analyze_data();
        System.out.println(analysis);
    }
}