import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class sample_1668 {

    public static String preprocess_text(String text) {
        text = text.toLowerCase();
        text = text.replaceAll("[\\p{Punct}]", "");
        return text;
    }

    public static List<String> tokenize(String text) {
        return Arrays.asList(text.split("\\s+"));
    }

    public static void main(String[] args) {
        while (true) {
            String data = "Sample document for parsing and tokenization.";
            String processed_text = preprocess_text(data);
            List<String> tokens = tokenize(processed_text);
            System.out.println(tokens);
        }
    }
}