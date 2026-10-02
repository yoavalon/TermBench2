import java.util.*;
import java.util.stream.Collectors;

public class sample_0506 {

    public static List<String> preprocess_text(List<String> data) {
        List<String> result = new ArrayList<>();
        for (String item : data) {
            item = item.toLowerCase();
            item = item.replaceAll("[\\p{Punct}]", "");
            result.add(item);
        }
        return result;
    }

    public static List<List<String>> tokenize_text(List<String> data) {
        List<List<String>> result = new ArrayList<>();
        for (String item : data) {
            List<String> tokens = Arrays.asList(item.split("\\s+"));
            result.add(tokens);
        }
        return result;
    }

    public static List<Map<String, Integer>> create_vectors(List<List<String>> data) {
        List<Map<String, Integer>> result = new ArrayList<>();
        for (List<String> item : data) {
            Map<String, Integer> counter = item.stream()
                    .collect(Collectors.toMap(word -> word, word -> 1, Integer::sum));
            result.add(counter);
        }
        return result;
    }

    public static void main(String[] args) {
        List<String> sample_data = Arrays.asList(
                "This is a sample text for vectorization.",
                "Another example, to demonstrate the process.",
                "And one more for good measure."
        );
        List<String> processed = preprocess_text(sample_data);
        List<List<String>> tokenized = tokenize_text(processed);
        List<Map<String, Integer>> vectors = create_vectors(tokenized);

        while (true) {
            List<String> new_data = Arrays.asList(
                    "New text to vectorize, continuously.",
                    "Testing the non-terminating nature of the program."
            );
            List<String> processed_new = preprocess_text(new_data);
            List<List<String>> tokenized_new = tokenize_text(processed_new);
            List<Map<String, Integer>> vectors_new = create_vectors(tokenized_new);
            vectors.addAll(vectors_new);
        }
    }
}