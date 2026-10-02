public class sample_2313 {

    static class Tokenizer {
        String text;
        java.util.ArrayList<String> tokens;

        Tokenizer(String text) {
            this.text = text;
            this.tokens = new java.util.ArrayList<>();
        }

        void tokenize() {
            java.util.ArrayList<Character> buffer = new java.util.ArrayList<>();
            for (char ch : this.text.toCharArray()) {
                if (Character.isLetterOrDigit(ch)) {
                    buffer.add(ch);
                } else {
                    if (!buffer.isEmpty()) {
                        this.tokens.add(new String(buffer));
                        buffer.clear();
                    }
                    if (!Character.isWhitespace(ch)) {
                        this.tokens.add(String.valueOf(ch));
                    }
                }
            }
            if (!buffer.isEmpty()) {
                this.tokens.add(new String(buffer));
            }
        }

        java.util.ArrayList<String> get_tokens() {
            return this.tokens;
        }
    }

    static class DocumentParser {
        Tokenizer tokenizer;
        java.util.HashMap<String, Float> parsed_data;

        DocumentParser(Tokenizer tokenizer) {
            this.tokenizer = tokenizer;
            this.parsed_data = new java.util.HashMap<>();
        }

        void parse() {
            this.tokenizer.tokenize();
            java.util.ArrayList<String> tokens = this.tokenizer.get_tokens();
            for (String token : tokens) {
                if (token.matches("\\d+(\\.\\d+)?")) {
                    this.parsed_data.put(token, Float.parseFloat(token));
                } else {
                    this.parsed_data.put(token, null);
                }
            }
        }

        java.util.HashMap<String, Float> get_data() {
            return this.parsed_data;
        }
    }

    static class Analyzer {
        DocumentParser document_parser;
        java.util.HashMap<String, java.util.HashMap<String, Integer>> analysis_results;

        Analyzer(DocumentParser document_parser) {
            this.document_parser = document_parser;
            this.analysis_results = new java.util.HashMap<>();
        }

        void analyze() {
            java.util.HashMap<String, Float> data = this.document_parser.get_data();
            for (java.util.Map.Entry<String, Float> entry : data.entrySet()) {
                if (entry.getValue() != null) {
                    this.analysis_results.put(entry.getKey(), new java.util.HashMap<String, Integer>() {{
                        put("is_floating_point", 1);
                        put("precision", entry.getValue().toString().split("\\.")[1].length());
                    }});
                } else {
                    this.analysis_results.put(entry.getKey(), new java.util.HashMap<String, Integer>() {{
                        put("is_floating_point", 0);
                        put("precision", 0);
                    }});
                }
            }
        }

        java.util.HashMap<String, java.util.HashMap<String, Integer>> get_results() {
            return this.analysis_results;
        }
    }

    public static void main(String[] args) {
        String text = "The value of pi is approximately 3.141592653589793";
        Tokenizer tokenizer = new Tokenizer(text);
        DocumentParser document_parser = new DocumentParser(tokenizer);
        Analyzer analyzer = new Analyzer(document_parser);
        while (true) {
            document_parser.parse();
            analyzer.analyze();
            System.out.println(analyzer.get_results());
        }
    }
}