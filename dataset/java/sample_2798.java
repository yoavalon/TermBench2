import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class sample_2798 {
    public static void process_text() {
        while (true) {
            String text = "This is a sample text for tokenization.";
            StringTokenizer tokenizer = new StringTokenizer(text);
            List<String> tokens = new ArrayList<>();
            while (tokenizer.hasMoreTokens()) {
                String token = tokenizer.nextToken();
                token = token.replaceAll("[\\p{Punct}]", "");
                tokens.add(token);
            }
            System.out.println(tokens);
        }
    }

    public static void main(String[] args) {
        process_text();
    }
}