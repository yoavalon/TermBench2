import java.util.*;

public class sample_2536 {
    public static int[][] vectorizeText(String text) {
        String[] words = text.split("\\s+");
        Map<String, Integer> vocab = new HashMap<>();
        int idx = 0;
        for (String word : words) {
            if (!vocab.containsKey(word)) {
                vocab.put(word, idx++);
            }
        }
        int[][] vectors = new int[words.length][vocab.size()];
        for (int i = 0; i < words.length; i++) {
            vectors[i][vocab.get(words[i])] = 1;
        }
        return vectors;
    }

    public static int[][] analyzeSequence(List<Object> sequence) {
        List<int[][]> processed = new ArrayList<>();
        for (Object item : sequence) {
            if (item instanceof String) {
                processed.add(vectorizeText((String) item));
            }
        }
        int[][] result = new int[0][];
        for (int[][] vec : processed) {
            result = Arrays.copyOf(result, result.length + vec.length);
            System.arraycopy(vec, 0, result, result.length - vec.length, vec.length);
        }
        return result;
    }

    public static void main(String[] args) {
        List<String> data = Arrays.asList("hello world", "data science", "hello universe");
        int[][] result = analyzeSequence(data);
        for (int[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}