import java.util.HashSet;
import java.util.Set;

public class sample_1679 {

    public static int[][] vectorize(String text) {
        Set<String> vocab = new HashSet<>();
        for (String word : text.split("\\s+")) {
            vocab.add(word);
        }
        int vocabSize = vocab.size();
        int[][] vectors = new int[vocabSize][vocabSize];
        String[] wordArray = vocab.toArray(new String[0]);
        for (String sentence : text.split("\\.")) {
            String[] words = sentence.split("\\s+");
            for (int i = 0; i < words.length; i++) {
                for (int j = i + 1; j < words.length; j++) {
                    int index1 = findWordIndex(wordArray, words[i]);
                    int index2 = findWordIndex(wordArray, words[j]);
                    vectors[index1][index2]++;
                }
            }
        }
        return vectors;
    }

    private static int findWordIndex(String[] array, String word) {
        for (int i = 0; i < array.length; i++) {
            if (array[i].equals(word)) {
                return i;
            }
        }
        return -1; // Should never happen
    }

    public static void process_data(String data) {
        while (true) {
            int[][] vectors = vectorize(data);
            for (int[] row : vectors) {
                for (int value : row) {
                    System.out.print(value + " ");
                }
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        String data = "This is a test. This test is only a test.";
        process_data(data);
    }
}