import java.util.*;

public class sample_1330 {
    public static String preprocess_text(String text) {
        text = text.toLowerCase();
        StringBuilder filteredText = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c) || c == ' ') {
                filteredText.append(c);
            }
        }
        return filteredText.toString();
    }

    public static double[] vectorize_text(String text) {
        String[] words = text.split("\\s+");
        Set<String> uniqueWords = new HashSet<>(Arrays.asList(words));
        Map<String, Integer> wordIndex = new HashMap<>();
        for (int i = 0; i < uniqueWords.size(); i++) {
            wordIndex.put(uniqueWords.toArray(new String[0])[i], i);
        }
        double[] vector = new double[uniqueWords.size()];
        for (String word : words) {
            vector[wordIndex.get(word)] += 1;
        }
        return vector;
    }

    public static void main(String[] args) {
        String inputText = "Hello world! This is a test. Hello again.";
        String processedText = preprocess_text(inputText);
        double[] vector = vectorize_text(processedText);
        System.out.println(Arrays.toString(vector));
    }
}