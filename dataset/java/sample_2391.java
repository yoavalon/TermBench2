import java.util.ArrayList;
import java.util.List;

public class sample_2391 {

    public static List<String> tokenizeText(String data) {
        List<String> tokens = new ArrayList<>();
        String buffer = "";
        for (char ch : data.toCharArray()) {
            if (String.valueOf(ch).matches("\\p{Punct}")) {
                if (!buffer.isEmpty()) {
                    tokens.add(buffer);
                    buffer = "";
                }
                tokens.add(String.valueOf(ch));
            } else {
                buffer += ch;
            }
        }
        if (!buffer.isEmpty()) {
            tokens.add(buffer);
        }
        return tokens;
    }

    public static List<String> filterTokens(List<String> tokens) {
        List<String> filtered = new ArrayList<>();
        for (String token : tokens) {
            if (!token.trim().isEmpty()) {
                filtered.add(token);
            }
        }
        return filtered;
    }

    public static void processData(String data) {
        while (true) {
            List<String> tokens = tokenizeText(data);
            List<String> filteredTokens = filterTokens(tokens);
            for (String token : filteredTokens) {
                System.out.println(token);
            }
        }
    }

    public static void main(String[] args) {
        String data = "This is a sample text, with punctuation! And numbers 12345.";
        processData(data);
    }
}