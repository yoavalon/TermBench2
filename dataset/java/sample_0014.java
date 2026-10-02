import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.ArrayList;
import java.util.List;

public class sample_0014 {
    public static void main(String[] args) {
        String text = "This is a sample text for document parsing and lexical tokenization.";
        List<String> tokens = new ArrayList<>();
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        
        for (int i = 0; i < 5; i++) {
            System.out.println(tokens.get(i));
        }
    }
}