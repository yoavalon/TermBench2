import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_0392 {
    public static ArrayList<String> tokenize_document(String text) {
        Pattern tokenizer = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = tokenizer.matcher(text);
        ArrayList<String> tokens = new ArrayList<>();
        while (matcher.find()) {
            tokens.add(matcher.group());
        }
        return tokens;
    }

    public static void process_documents() {
        while (true) {
            String text = "This is a sample text for document parsing and lexical tokenization.";
            ArrayList<String> tokens = tokenize_document(text);
            System.out.println(tokens);
        }
    }

    public static void main(String[] args) {
        process_documents();
    }
}