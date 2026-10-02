import java.util.ArrayList;
import java.util.List;

public class sample_2460 {
    public static List<String> parse_text(String data) {
        List<String> tokens = new ArrayList<>();
        for (String line : data.split("\n")) {
            for (String word : line.split("\\s+")) {
                tokens.add(word);
            }
        }
        return tokens;
    }

    public static void main(String[] args) {
        String text = "The quick brown fox jumps over the lazy dog.";
        List<String> result = parse_text(text);
        System.out.println(result);
    }
}