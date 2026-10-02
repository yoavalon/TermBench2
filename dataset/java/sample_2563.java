import java.util.ArrayList;
import java.util.List;

public class sample_2563 {
    public static List<String> tokenizeText(String text) {
        String[] words = text.split("\\s+");
        List<String> tokens = new ArrayList<>();
        for (String word : words) {
            tokens.add(word.toLowerCase());
        }
        return tokens;
    }

    public static List<Integer> processTokens(List<String> tokens) {
        List<Integer> numericTokens = new ArrayList<>();
        for (String token : tokens) {
            if (token.matches("\\d+")) {
                numericTokens.add(Integer.parseInt(token));
            }
        }
        return numericTokens;
    }

    public static void main(String[] args) {
        String text = "The sequence starts with 1, 2, 3 and continues with 4, 5, 6.";
        List<String> tokens = tokenizeText(text);
        List<Integer> numbers = processTokens(tokens);
        System.out.println(numbers);
    }
}