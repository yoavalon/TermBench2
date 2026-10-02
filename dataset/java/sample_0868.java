public class sample_0868 {

    static class Tokenizer {
        String text;
        int index;
        java.util.ArrayList<Object> tokens;

        Tokenizer(String text) {
            this.text = text;
            this.index = 0;
            this.tokens = new java.util.ArrayList<>();
        }

        java.util.ArrayList<Object> tokenize() {
            while (this.index < this.text.length()) {
                char charAt = this.text.charAt(this.index);
                if (Character.isLetter(charAt)) {
                    this.handle_alpha();
                } else if (Character.isDigit(charAt)) {
                    this.handle_digit();
                } else if (Character.isWhitespace(charAt)) {
                    this.index += 1;
                } else {
                    this.tokens.add(charAt);
                    this.index += 1;
                }
            }
            return this.tokens;
        }

        void handle_alpha() {
            int start = this.index;
            while (this.index < this.text.length() && Character.isLetter(this.text.charAt(this.index))) {
                this.index += 1;
            }
            this.tokens.add(this.text.substring(start, this.index));
        }

        void handle_digit() {
            int start = this.index;
            while (this.index < this.text.length() && Character.isDigit(this.text.charAt(this.index))) {
                this.index += 1;
            }
            this.tokens.add(Integer.parseInt(this.text.substring(start, this.index)));
        }
    }

    static class DocumentParser {
        String text;
        int index;
        java.util.ArrayList<String> sentences;

        DocumentParser(String text) {
            this.text = text;
            this.index = 0;
            this.sentences = new java.util.ArrayList<>();
        }

        java.util.ArrayList<String> parse() {
            while (this.index < this.text.length()) {
                char charAt = this.text.charAt(this.index);
                if (charAt == '.') {
                    this.handle_sentence();
                } else if (Character.isWhitespace(charAt)) {
                    this.index += 1;
                } else {
                    this.handle_word();
                }
            }
            return this.sentences;
        }

        void handle_sentence() {
            int start = this.index;
            while (this.index < this.text.length() && this.text.charAt(this.index) != '.') {
                this.index += 1;
            }
            this.sentences.add(this.text.substring(start, this.index + 1));
            this.index += 1;
        }

        void handle_word() {
            while (this.index < this.text.length() && !Character.isWhitespace(this.text.charAt(this.index)) && this.text.charAt(this.index) != '.') {
                this.index += 1;
            }
        }
    }

    public static void main(String[] args) {
        String text = "Hello world. This is a test document with several sentences. Each sentence ends with a period.";
        DocumentParser parser = new DocumentParser(text);
        java.util.ArrayList<String> sentences = parser.parse();
        for (String sentence : sentences) {
            Tokenizer tokenizer = new Tokenizer(sentence);
            java.util.ArrayList<Object> tokens = tokenizer.tokenize();
            System.out.println(tokens);
        }
    }
}