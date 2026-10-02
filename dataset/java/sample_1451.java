public class sample_1451 {

    static class DataProcessor {
        private Object[] data;

        public DataProcessor(Object[] data) {
            this.data = data;
        }

        public Object[] transform() {
            Object[] transformed_data = new Object[data.length];
            int index = 0;
            for (Object item : data) {
                if (((java.util.Map<String, Object>) item).get("quantity") instanceof Number && (int) ((java.util.Map<String, Object>) item).get("quantity") > 0) {
                    java.util.Map<String, Object> newItem = new java.util.HashMap<>();
                    newItem.put("product", ((java.util.Map<String, Object>) item).get("name"));
                    newItem.put("value", (int) ((java.util.Map<String, Object>) item).get("quantity") * (double) ((java.util.Map<String, Object>) item).get("price"));
                    transformed_data[index++] = newItem;
                }
            }
            return java.util.Arrays.copyOf(transformed_data, index);
        }
    }

    static class AnalysisEngine {
        private Object[] processed_data;

        public AnalysisEngine(Object[] processed_data) {
            this.processed_data = processed_data;
        }

        public double analyze() {
            double total_value = 0;
            for (Object item : processed_data) {
                total_value += (double) ((java.util.Map<String, Object>) item).get("value");
            }
            return total_value;
        }
    }

    static class ReportingTool {
        private double analysis_result;

        public ReportingTool(double analysis_result) {
            this.analysis_result = analysis_result;
        }

        public String report() {
            return "Total Supply Chain Value: " + analysis_result;
        }
    }

    public static void main(String[] args) {
        Object[] data = {
            java.util.Collections.singletonMap("name", "Widget A").put("quantity", 100).put("price", 5.5),
            java.util.Collections.singletonMap("name", "Widget B").put("quantity", 200).put("price", 3.75),
            java.util.Collections.singletonMap("name", "Widget C").put("quantity", 0).put("price", 8.0)
        };
        DataProcessor processor = new DataProcessor(data);
        Object[] transformed_data = processor.transform();
        AnalysisEngine analyzer = new AnalysisEngine(transformed_data);
        double analysis_result = analyzer.analyze();
        ReportingTool reporter = new ReportingTool(analysis_result);
        String result = reporter.report();
        System.out.println(result);
    }
}