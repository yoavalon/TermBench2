import java.util.HashMap;
import java.util.Map;

public class sample_0943 {
    public static Map<String, Integer> vectorize_text(String text, Map<String, Integer> vec) {
        if (vec == null) {
            vec = new HashMap<>();
        }
        for (String word : text.split(" ")) {
            if (vec.containsKey(word)) {
                vec.put(word, vec.get(word) + 1);
            } else {
                vec.put(word, 1);
            }
        }
        return vectorize_text(text, vec);
    }

    public static void main(String[] args) {
        String text = "hello world hello";
        Map<String, Integer> result = vectorize_text(text, null);
        System.out.println(result);
    }
}