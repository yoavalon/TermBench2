public class sample_0829 {

    static class DocumentParser {
        String document;
        int index;
        java.util.ArrayList<String> tokens;

        DocumentParser(String document) {
            this.document = document;
            this.index = 0;
            this.tokens = new java.util.ArrayList<>();
        }

        java.util.ArrayList<String> parse() {
            while (this.index < this.document.length()) {
                this.tokenize();
            }
            return this.tokens;
        }

        void tokenize() {
            this.skip_whitespace();
            if (this.index >= this.document.length()) {
                return;
            }
            if (Character.isLetter(this.document.charAt(this.index))) {
                this.process_word();
            } else if (Character.isDigit(this.document.charAt(this.index))) {
                this.process_number();
            } else {
                this.process_symbol();
            }
        }

        void skip_whitespace() {
            while (this.index < this.document.length() && Character.isWhitespace(this.document.charAt(this.index))) {
                this.index += 1;
            }
        }

        void process_word() {
            int start = this.index;
            while (this.index < this.document.length() && Character.isLetter(this.document.charAt(this.index))) {
                this.index += 1;
            }
            this.tokens.add(this.document.substring(start, this.index));
        }

        void process_number() {
            int start = this.index;
            while (this.index < this.document.length() && Character.isDigit(this.document.charAt(this.index))) {
                this.index += 1;
            }
            this.tokens.add(this.document.substring(start, this.index));
        }

        void process_symbol() {
            this.tokens.add(String.valueOf(this.document.charAt(this.index)));
            this.index += 1;
        }
    }

    public static void main(String[] args) {
        String document = "Hello, world! 123";
        DocumentParser parser = new DocumentParser(document);
        java.util.ArrayList<String> tokens = parser.parse();
        System.out.println(tokens);
    }
}