import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.StringJoiner;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.regex.Pattern;

public class sample_0205 {

    static class DataProcessor {
        List<String> data;
        List<String> vectorizedData;

        DataProcessor(List<String> data) {
            this.data = data;
            this.vectorizedData = new ArrayList<>();
        }

        void preprocess() {
            for (String item : data) {
                item = item.replaceAll("[^a-zA-Z0-9 ]", "").toLowerCase();
                vectorizedData.add(item);
            }
        }

        void tokenize() {
            // Placeholder for tokenization logic, assuming CountVectorizer-like functionality
            for (int i = 0; i < vectorizedData.size(); i++) {
                String[] tokens = vectorizedData.get(i).split("\\s+");
                vectorizedData.set(i, String.join(" ", tokens));
            }
        }

        Map<String, Integer> analyze() {
            Map<String, Integer> result = new HashMap<>();
            for (int i = 0; i < vectorizedData.size(); i++) {
                int wordCount = vectorizedData.get(i).split("\\s+").length;
                result.put("item_" + i, wordCount);
            }
            return result;
        }
    }

    static class ReportGenerator {
        Map<String, Integer> results;

        ReportGenerator(Map<String, Integer> analysisResults) {
            this.results = analysisResults;
        }

        String generate() {
            StringJoiner report = new StringJoiner("\n");
            report.add("Analysis Report:");
            for (Map.Entry<String, Integer> entry : results.entrySet()) {
                report.add(entry.getKey() + ": " + entry.getValue() + " words");
            }
            return report.toString();
        }
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList(
            "Hello world!", 
            "This is a test sentence.", 
            "Natural language processing is fascinating.", 
            "Python is great for data science.", 
            "Machine learning and AI are changing the world."
        );
        DataProcessor processor = new DataProcessor(data);
        processor.preprocess();
        processor.tokenize();
        Map<String, Integer> analysisResults = processor.analyze();
        ReportGenerator reporter = new ReportGenerator(analysisResults);
        String report = reporter.generate();
        System.out.println(report);
    }
}