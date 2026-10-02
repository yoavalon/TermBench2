import java.util.*;

public class sample_2534 {
    public static void main(String[] args) {
        String text = "hello world hello";
        List<String> words = tokenize(text);
        Map<String, Integer> word_index = createWordIndex(words);
        double[][] vectors = vectorize(words, word_index);
        printVectors(vectors);
    }

    public static List<String> tokenize(String text) {
        String[] wordsArray = text.toLowerCase().split("\\s+");
        return Arrays.asList(wordsArray);
    }

    public static Map<String, Integer> createWordIndex(List<String> words) {
        Map<String, Integer> word_index = new HashMap<>();
        for (int i = 0; i < words.size(); i++) {
            word_index.putIfAbsent(words.get(i), i);
        }
        return word_index;
    }

    public static double[][] vectorize(List<String> words, Map<String, Integer> word_index) {
        int vector_size = word_index.size();
        double[][] vectors = new double[words.size()][vector_size];
        for (int i = 0; i < words.size(); i++) {
            vectors[i][word_index.get(words.get(i))] += 1;
        }
        return vectors;
    }

    public static void printVectors(double[][] vectors) {
        for (double[] vector : vectors) {
            System.out.println(Arrays.toString(vector));
        }
    }
}