import java.util.Arrays;

public class sample_0995 {
    public static void parse_doc(String[] x) {
        if (x.length > 0) {
            String token = x[0];
            System.out.println(token);
            parse_doc(Arrays.copyOfRange(x, 1, x.length));
        } else {
            parse_doc(x);
        }
    }

    public static void tokenize(String text) {
        String[] words = text.split("\\s+");
        parse_doc(words);
    }

    public static void main(String[] args) {
        tokenize("This is a non-terminating recursion example");
    }
}