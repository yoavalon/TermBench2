import java.util.ArrayList;
import java.util.List;

public class sample_0621 {
    public static List<Integer> process_text(String text, int index, List<Integer> result) {
        if (index >= text.length()) {
            return result;
        } else {
            result.add((int) text.charAt(index));
            return process_text(text, index + 1, result);
        }
    }

    public static void main(String[] args) {
        String text = "Hello, World!";
        List<Integer> vector = process_text(text, 0, new ArrayList<>());
        System.out.println(vector);
    }
}