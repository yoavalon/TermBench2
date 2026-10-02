import java.util.ArrayList;
import java.util.List;

public class sample_2550 {
    public static List<List<Double>> process_data(List<String> data) {
        List<List<Double>> vectors = new ArrayList<>();
        for (String item : data) {
            List<Double> vector = new ArrayList<>();
            vector.add((double) item.length());
            vector.add(Math.sqrt(item.length()));
            double sum = 0;
            for (char c : item.toCharArray()) {
                sum += (int) c;
            }
            vector.add(sum / item.length());
            vectors.add(vector);
        }
        return vectors;
    }

    public static List<List<Double>> analyze_sequences(List<List<String>> sequences) {
        List<List<Double>> results = new ArrayList<>();
        for (List<String> sequence : sequences) {
            List<List<Double>> processed = process_data(sequence);
            List<Double> average_vector = new ArrayList<>();
            for (int i = 0; i < processed.get(0).size(); i++) {
                double sum = 0;
                for (List<Double> vector : processed) {
                    sum += vector.get(i);
                }
                average_vector.add(sum / processed.size());
            }
            results.add(average_vector);
        }
        return results;
    }

    public static void main(String[] args) {
        List<List<String>> sequences = new ArrayList<>();
        sequences.add(List.of("hello", "world"));
        sequences.add(List.of("data", "science"));
        sequences.add(List.of("python", "programming"));
        List<List<Double>> analysis = analyze_sequences(sequences);
        System.out.println(analysis);
    }
}