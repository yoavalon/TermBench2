import java.util.ArrayList;
import java.util.List;

public class sample_0660 {
    public static List<Integer> vectorize_text(String text, int index, List<Integer> result) {
        if (result == null) {
            result = new ArrayList<>();
        }
        if (index < text.length()) {
            result.add((int) text.charAt(index));
            return vectorize_text(text, index + 1, result);
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(vectorize_text("hello", 0, null));
    }
}