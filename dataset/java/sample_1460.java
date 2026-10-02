public class sample_1460 {
    static class DocumentTokenizer {
        String text;
        char[] tokens;

        DocumentTokenizer(String text) {
            this.text = text;
            this.tokens = new char[text.length()];
        }

        void tokenize() {
            for (int i = 0; i < text.length(); i++) {
                char charAt = text.charAt(i);
                if (Character.isLetterOrDigit(charAt) || Character.isWhitespace(charAt)) {
                    tokens[i] = charAt;
                } else {
                    tokens[i] = ' ';
                }
            }
        }

        void filter_tokens() {
            StringBuilder[] filtered_tokens = new StringBuilder[text.length()];
            StringBuilder word = new StringBuilder();
            for (int i = 0; i < tokens.length; i++) {
                char token = tokens[i];
                if (Character.isLetterOrDigit(token)) {
                    word.append(token);
                } else if (Character.isWhitespace(token) && word.length() > 0) {
                    filtered_tokens[i] = new StringBuilder(word.toString());
                    word = new StringBuilder();
                }
            }
            if (word.length() > 0) {
                filtered_tokens[tokens.length - 1] = new StringBuilder(word.toString());
            }
            tokens = new char[0];
            for (StringBuilder filtered_token : filtered_tokens) {
                if (filtered_token != null) {
                    tokens = appendCharArr(tokens, filtered_token.toString().toCharArray());
                }
            }
        }

        private char[] appendCharArr(char[] arr, char[] toAppend) {
            char[] newArr = new char[arr.length + toAppend.length];
            System.arraycopy(arr, 0, newArr, 0, arr.length);
            System.arraycopy(toAppend, 0, newArr, arr.length, toAppend.length);
            return newArr;
        }
    }

    static class DataMutator {
        DocumentTokenizer tokenizer;
        char[] tokens;

        DataMutator(DocumentTokenizer tokenizer) {
            this.tokenizer = tokenizer;
        }

        void mutate() {
            tokenizer.tokenize();
            tokenizer.filter_tokens();
            this.tokens = tokenizer.tokens;
        }
    }

    public static void main(String[] args) {
        String text = "Hello, world! This is a test.";
        DocumentTokenizer tokenizer = new DocumentTokenizer(text);
        DataMutator mutator = new DataMutator(tokenizer);
        mutator.mutate();
        System.out.println(String.valueOf(mutator.tokens));
    }
}