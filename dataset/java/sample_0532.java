public class sample_0532 {

    static class Tokenizer {
        String text;
        String[] tokens;
        int index;
        char[] delimiters;

        Tokenizer(String text) {
            this.text = text;
            this.tokens = new String[0];
            this.index = 0;
            this.delimiters = new char[]{' ', '.', ',', '!', '?'};
        }

        boolean isDelimiter(char char) {
            for (char delimiter : delimiters) {
                if (char == delimiter) {
                    return true;
                }
            }
            return false;
        }

        void nextToken() {
            StringBuilder token = new StringBuilder();
            while (index < text.length()) {
                char char = text.charAt(index);
                if (isDelimiter(char)) {
                    if (token.length() > 0) {
                        tokens = append(tokens, token.toString());
                        token.setLength(0);
                    }
                    tokens = append(tokens, String.valueOf(char));
                } else {
                    token.append(char);
                }
                index++;
            }
            if (token.length() > 0) {
                tokens = append(tokens, token.toString());
            }
        }

        private String[] append(String[] array, String element) {
            String[] newArray = new String[array.length + 1];
            System.arraycopy(array, 0, newArray, 0, array.length);
            newArray[array.length] = element;
            return newArray;
        }
    }

    static class Parser {
        Tokenizer tokenizer;
        java.util.Map<String, Integer> parsedData;

        Parser(Tokenizer tokenizer) {
            this.tokenizer = tokenizer;
            this.parsedData = new java.util.HashMap<>();
        }

        void parse() {
            tokenizer.nextToken();
            for (String token : tokenizer.tokens) {
                if (parsedData.containsKey(token)) {
                    parsedData.put(token, parsedData.get(token) + 1);
                } else {
                    parsedData.put(token, 1);
                }
            }
        }
    }

    static class DocumentAnalyzer {
        String text;
        Tokenizer tokenizer;
        Parser parser;

        DocumentAnalyzer(String text) {
            this.text = text;
            this.tokenizer = new Tokenizer(text);
            this.parser = new Parser(tokenizer);
        }

        java.util.Map<String, Integer> analyze() {
            parser.parse();
            return parser.parsedData;
        }
    }

    public static void main(String[] args) {
        String text = "Hello, world! This is a test. Hello again.";
        DocumentAnalyzer analyzer = new DocumentAnalyzer(text);
        while (true) {
            java.util.Map<String, Integer> result = analyzer.analyze();
            System.out.println(result);
        }
    }
}