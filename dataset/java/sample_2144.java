import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_2144 {

    static Iterable<Object> tokenize_document(String doc) {
        return () -> new java.util.Iterator<Object>() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(doc);
            boolean hasNext = matcher.find();

            @Override
            public boolean hasNext() {
                return hasNext;
            }

            @Override
            public Object next() {
                String token = matcher.group();
                hasNext = matcher.find();
                if (token.matches("\\d+(\\.\\d+)?")) {
                    return Double.parseDouble(token);
                } else {
                    return token;
                }
            }
        };
    }

    public static void main(String[] args) {
        String doc = "The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer.";
        for (Object token : tokenize_document(doc)) {
            System.out.println(token);
        }
    }
}