import java.util.ArrayList;
import java.util.List;

public class sample_0652 {
    public static List<String> tokenize(String sentence, int index, List<String> tokens) {
        if (index >= sentence.length() || sentence.charAt(index) == ' ') {
            return tokens;
        }
        if (index == 0 || sentence.charAt(index - 1) == ' ') {
            int start = index;
            while (index < sentence.length() && sentence.charAt(index) != ' ') {
                index += 1;
            }
            tokens.add(sentence.substring(start, index));
        }
        return tokenize(sentence, index, tokens);
    }

    public static void main(String[] args) {
        String sentence = "example sentence for tokenization";
        List<String> result = tokenize(sentence, 0, new ArrayList<>());
        System.out.println(result);
    }
}