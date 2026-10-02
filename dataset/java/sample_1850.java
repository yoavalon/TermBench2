import java.util.HashMap;
import java.util.Map;

public class sample_1850 {
    public static void main(String[] args) {
        Map<String, Integer> vocab = new HashMap<>();
        vocab.put("hello", 0);
        vocab.put("world", 1);
        vocab.put("test", 2);
        String text = "hello world test";
        double[] result = vectorizeText(text, vocab, 1000);
        for (double value : result) {
            System.out.print(value + " ");
        }
    }

    public static double[] vectorizeText(String text, Map<String, Integer> vocab, int vocabSize) {
        double[] vec = new double[vocabSize];
        for (String word : text.split(" ")) {
            if (vocab.containsKey(word)) {
                vec[vocab.get(word)] += 1;
            }
        }
        return vec;
    }
}