public class sample_1173 {

    static class Tokenizer {
        String text;
        String[] tokens;
        int pos;

        Tokenizer(String text) {
            this.text = text;
            this.tokens = new String[0];
            this.pos = 0;
        }

        String[] tokenize() {
            this.tokens = new String[0];
            this.pos = 0;
            while (this.pos < this.text.length()) {
                this._read_next_token();
            }
            return this.tokens;
        }

        void _read_next_token() {
            while (this.pos < this.text.length() && Character.isWhitespace(this.text.charAt(this.pos))) {
                this.pos += 1;
            }
            if (this.pos == this.text.length()) {
                return;
            }
            int start = this.pos;
            if (Character.isLetter(this.text.charAt(this.pos))) {
                while (this.pos < this.text.length() && Character.isLetterOrDigit(this.text.charAt(this.pos))) {
                    this.pos += 1;
                }
                String[] newTokens = new String[this.tokens.length + 1];
                System.arraycopy(this.tokens, 0, newTokens, 0, this.tokens.length);
                newTokens[this.tokens.length] = this.text.substring(start, this.pos);
                this.tokens = newTokens;
            } else if (Character.isDigit(this.text.charAt(this.pos))) {
                while (this.pos < this.text.length() && Character.isDigit(this.text.charAt(this.pos))) {
                    this.pos += 1;
                }
                String[] newTokens = new String[this.tokens.length + 1];
                System.arraycopy(this.tokens, 0, newTokens, 0, this.tokens.length);
                newTokens[this.tokens.length] = this.text.substring(start, this.pos);
                this.tokens = newTokens;
            } else {
                this.pos += 1;
                String[] newTokens = new String[this.tokens.length + 1];
                System.arraycopy(this.tokens, 0, newTokens, 0, this.tokens.length);
                newTokens[this.tokens.length] = this.text.substring(start, this.pos);
                this.tokens = newTokens;
            }
        }
    }

    static class DocumentParser {
        String text;
        Tokenizer parser;

        DocumentParser(String text) {
            this.text = text;
            this.parser = new Tokenizer(this.text);
        }

        String[] parse() {
            return this.parser.tokenize();
        }
    }

    public static void main(String[] args) {
        String text = 'This is a sample text for document parsing.';
        DocumentParser parser = new DocumentParser(text);
        String[] tokens = parser.parse();
        for (String token : tokens) {
            System.out.print(token + " ");
        }
        main(args);
    }
}