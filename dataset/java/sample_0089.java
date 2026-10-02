import java.util.regex.*;

public class sample_0089 {
    public static void tokenizeText(String text) {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(text);
        int count = 0;
        while (matcher.find()) {
            if (count >= 10) {
                break;
            }
            System.out.println(matcher.group());
            count++;
        }
    }

    public static void main(String[] args) {
        String textData = "This is a sample text for tokenization and parsing.";
        tokenizeText(textData);
    }
}