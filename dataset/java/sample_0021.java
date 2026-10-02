import java.util.Arrays;

public class sample_0021 {
    public static String[] parse_and_tokenize(String doc, int max_tokens) {
        String[] tokens = doc.split(" ");
        return Arrays.copyOfRange(tokens, 0, Math.min(max_tokens, tokens.length));
    }

    public static void main(String[] args) {
        String doc = "This is a sample document for parsing and tokenization.";
        int max_tokens = 5;
        String[] result = parse_and_tokenize(doc, max_tokens);
        System.out.println(Arrays.toString(result));
    }
}