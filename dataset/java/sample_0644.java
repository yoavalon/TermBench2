import java.util.ArrayList;
import java.util.List;

public class sample_0644 {
    public static List<List<String>> vectorize_text(List<String> text, int index, List<List<String>> result) {
        if (index == text.size()) {
            return result;
        }
        String word = text.get(index);
        List<String> splitWord = List.of(word.split(" "));
        result.add(splitWord);
        return vectorize_text(text, index + 1, result);
    }

    public static void main(String[] args) {
        List<String> text_data = List.of("hello world", "data science", "python programming");
        List<List<String>> vectorized_data = vectorize_text(text_data, 0, new ArrayList<>());
        System.out.println(vectorized_data);
    }
}