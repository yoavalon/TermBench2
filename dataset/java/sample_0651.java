import java.util.List;
import java.util.Arrays;

public class sample_0651 {
    public static List<Integer> vectorize_text(String text, List<Integer> vec, int index) {
        if (index == text.length()) {
            return vec;
        }
        char ch = Character.toLowerCase(text.charAt(index));
        if ('a' <= ch && ch <= 'z') {
            vec.set(ch - 'a', vec.get(ch - 'a') + 1);
        }
        return vectorize_text(text, vec, index + 1);
    }

    public static void main(String[] args) {
        String text = "Hello, World!";
        List<Integer> vec = Arrays.asList(new Integer[26]);
        for (int i = 0; i < 26; i++) {
            vec.set(i, 0);
        }
        List<Integer> result = vectorize_text(text, vec, 0);
        System.out.println(result);
    }
}