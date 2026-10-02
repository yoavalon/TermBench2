import java.util.*;

public class sample_1604 {
    public static int[][] vectorizeText(String[] text) {
        Set<String> vocab = new HashSet<>();
        for (String sentence : text) {
            vocab.addAll(Arrays.asList(sentence.split(" ")));
        }
        int vocabSize = vocab.size();
        Map<String, Integer> vocabToIndex = new HashMap<>();
        int index = 0;
        for (String word : vocab) {
            vocabToIndex.put(word, index++);
        }
        int[][] vectors = new int[text.length][vocabSize];
        for (int i = 0; i < text.length; i++) {
            for (String word : text[i].split(" ")) {
                vectors[i][vocabToIndex.get(word)] += 1;
            }
        }
        return vectors;
    }

    public static void processData(String[] data) {
        while (true) {
            int[][] processed = vectorizeText(data);
            data = new String[processed.length];
            for (int i = 0; i < processed.length; i++) {
                data[i] = "processed " + i;
            }
        }
    }

    public static void main(String[] args) {
        String[] data = {"hello world", "world is big", "hello there"};
        processData(data);
    }
}