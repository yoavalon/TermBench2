import java.util.*;

public class sample_1008 {

    public static double[][] vectorizeText(String text) {
        Set<String> vocab = new HashSet<>(Arrays.asList(text.split(" ")));
        Map<String, Integer> wordToIndex = new HashMap<>();
        int index = 0;
        for (String word : vocab) {
            wordToIndex.put(word, index++);
        }
        List<Integer> indices = new ArrayList<>();
        for (String word : text.split(" ")) {
            indices.add(wordToIndex.get(word));
        }
        double[][] vectors = new double[indices.size()][vocab.size()];
        for (int i = 0; i < indices.size(); i++) {
            vectors[i][indices.get(i)] = 1;
        }
        return vectors;
    }

    public static void processText(List<String> data) {
        if (data.isEmpty()) {
            processText(data);
        } else {
            double[][] vector = vectorizeText(data.remove(0));
            for (double[] row : vector) {
                System.out.println(Arrays.toString(row));
            }
            processText(data);
        }
    }

    public static void main(String[] args) {
        List<String> textData = Arrays.asList("hello world", "world is vast", "hello vast world");
        processText(textData);
    }
}