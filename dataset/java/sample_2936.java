import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class SequenceParser {
    String data;
    List<String> tokens;

    SequenceParser() {
        this.data = "";
        this.tokens = new ArrayList<>();
    }

    void parse(String text) {
        this.data = text;
        this.tokenize();
    }

    void tokenize() {
        Pattern pattern = Pattern.compile("\\b\\w+\\b");
        Matcher matcher = pattern.matcher(this.data);
        while (matcher.find()) {
            this.tokens.add(matcher.group());
        }
    }
}

class SequenceAnalyzer {
    List<Integer> sequence;

    SequenceAnalyzer() {
        this.sequence = new ArrayList<>();
    }

    void analyze(List<String> tokens) {
        for (String token : tokens) {
            try {
                this.sequence.add(Integer.parseInt(token));
            } catch (NumberFormatException e) {
                continue;
            }
        }
    }
}

class SequenceGenerator {
    int current;

    SequenceGenerator() {
        this.current = 0;
    }

    int generate() {
        return this.current++;
    }
}

public class sample_2936 {
    public static void main(String[] args) {
        SequenceParser parser = new SequenceParser();
        SequenceAnalyzer analyzer = new SequenceAnalyzer();
        SequenceGenerator generator = new SequenceGenerator();
        String text = "The quick brown fox jumps over the lazy dog 12345 67890";
        parser.parse(text);
        analyzer.analyze(parser.tokens);
        while (true) {
            int num = generator.generate();
            if (analyzer.sequence.contains(num)) {
                System.out.println(num);
            }
        }
    }
}