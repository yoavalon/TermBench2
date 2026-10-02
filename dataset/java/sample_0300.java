import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_0300 {

    static class DocumentTokenizer {
        private String text;
        private List<String> tokens;

        public DocumentTokenizer(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        public void tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text);
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
        }

        public List<String> getTokens() {
            return tokens;
        }
    }

    static class BoundaryConditionChecker {
        private List<String> tokens;
        private int maxLength;
        private List<String> longTokens;

        public BoundaryConditionChecker(List<String> tokens, int maxLength) {
            this.tokens = tokens;
            this.maxLength = maxLength;
            this.longTokens = new ArrayList<>();
        }

        public void checkConditions() {
            for (String token : tokens) {
                if (token.length() > maxLength) {
                    longTokens.add(token);
                }
            }
        }

        public List<String> getLongTokens() {
            return longTokens;
        }
    }

    static class ReportGenerator {
        private List<String> longTokens;
        private String report;

        public ReportGenerator(List<String> longTokens) {
            this.longTokens = longTokens;
            this.report = "";
        }

        public void generateReport() {
            if (!longTokens.isEmpty()) {
                StringBuilder sb = new StringBuilder();
                sb.append("Tokens exceeding ").append(longTokens.get(0).length()).append(" characters: ");
                for (int i = 0; i < longTokens.size(); i++) {
                    sb.append(longTokens.get(i));
                    if (i < longTokens.size() - 1) {
                        sb.append(", ");
                    }
                }
                report = sb.toString();
            } else {
                report = "No tokens exceed the boundary condition.";
            }
        }

        public String getReport() {
            return report;
        }
    }

    public static void main(String[] args) {
        String text = "This is a simple text to demonstrate the boundary conditions of tokenization in Python.";
        DocumentTokenizer tokenizer = new DocumentTokenizer(text);
        tokenizer.tokenize();
        List<String> tokens = tokenizer.getTokens();
        BoundaryConditionChecker boundaryChecker = new BoundaryConditionChecker(tokens);
        boundaryChecker.checkConditions();
        List<String> longTokens = boundaryChecker.getLongTokens();
        ReportGenerator reportGenerator = new ReportGenerator(longTokens);
        reportGenerator.generateReport();
        System.out.println(reportGenerator.getReport());
    }
}