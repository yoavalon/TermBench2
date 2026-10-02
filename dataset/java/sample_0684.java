import java.util.ArrayList;
import java.util.List;

public class sample_0684 {
    public static List<String> vectorize_text(String text, List<String> vectors, int depth) {
        if (depth == 0) {
            return vectors;
        }
        String[] words = text.split(" ");
        for (String word : words) {
            vectors.add(word);
        }
        return vectorize_text(text, vectors, depth - 1);
    }

    public static void main(String[] args) {
        String text = "recursion in natural language processing";
        List<String> vectors = new ArrayList<>();
        List<String> result = vectorize_text(text, vectors, 3);
        System.out.println(result);
    }
}