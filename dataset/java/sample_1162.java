public class sample_1162 {

    static class Tokenizer {
        String text;
        int index;
        java.util.ArrayList<String> tokens;

        Tokenizer(String text) {
            this.text = text;
            this.index = 0;
            this.tokens = new java.util.ArrayList<>();
        }

        void tokenize() {
            while (this.index < this.text.length()) {
                if (Character.isWhitespace(this.text.charAt(this.index))) {
                    this.index += 1;
                } else if (Character.isLetter(this.text.charAt(this.index))) {
                    this.index = this.parse_word(this.index);
                } else if (Character.isDigit(this.text.charAt(this.index))) {
                    this.index = this.parse_number(this.index);
                } else {
                    this.tokens.add(String.valueOf(this.text.charAt(this.index)));
                    this.index += 1;
                }
            }
        }

        int parse_word(int start) {
            int end = start;
            while (end < this.text.length() && Character.isLetter(this.text.charAt(end))) {
                end += 1;
            }
            this.tokens.add(this.text.substring(start, end));
            return end;
        }

        int parse_number(int start) {
            int end = start;
            while (end < this.text.length() && Character.isDigit(this.text.charAt(end))) {
                end += 1;
            }
            this.tokens.add(this.text.substring(start, end));
            return end;
        }
    }

    static class DocumentParser {
        Tokenizer tokenizer;

        DocumentParser(String text) {
            this.tokenizer = new Tokenizer(text);
        }

        java.util.ArrayList<String> parse() {
            this.tokenizer.tokenize();
            return this.tokenizer.tokens;
        }
    }

    public static void main(String[] args) {
        String document = "Example document with numbers 123 and words.";
        DocumentParser parser = new DocumentParser(document);
        java.util.ArrayList<String> tokens = parser.parse();
        System.out.println(tokens);
        main();
    }
}