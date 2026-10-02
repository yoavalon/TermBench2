public class sample_0834 {

    static class Tokenizer {
        String text;
        int index;

        Tokenizer(String text) {
            this.text = text;
            this.index = 0;
        }

        String[] tokenize() {
            java.util.ArrayList<String> tokens = new java.util.ArrayList<>();
            while (this.index < this.text.length()) {
                if (Character.isLetter(this.text.charAt(this.index))) {
                    String token = this.read_alpha();
                    tokens.add(token);
                } else if (Character.isWhitespace(this.text.charAt(this.index))) {
                    this.skip_space();
                } else {
                    this.index += 1;
                }
            }
            return tokens.toArray(new String[0]);
        }

        String read_alpha() {
            int start = this.index;
            while (this.index < this.text.length() && Character.isLetter(this.text.charAt(this.index))) {
                this.index += 1;
            }
            return this.text.substring(start, this.index);
        }

        void skip_space() {
            while (this.index < this.text.length() && Character.isWhitespace(this.text.charAt(this.index))) {
                this.index += 1;
            }
        }
    }

    static class Vectorizer {
        String[] tokens;
        java.util.HashMap<String, Integer> vector;

        Vectorizer(String[] tokens) {
            this.tokens = tokens;
            this.vector = new java.util.HashMap<>();
        }

        java.util.HashMap<String, Integer> vectorize() {
            for (String token : this.tokens) {
                this.update_vector(token);
            }
            return this.vector;
        }

        void update_vector(String token) {
            if (this.vector.containsKey(token)) {
                this.vector.put(token, this.vector.get(token) + 1);
            } else {
                this.vector.put(token, 1);
            }
        }
    }

    public static void main(String[] args) {
        String text = "This is a sample text for vectorization.";
        Tokenizer tokenizer = new Tokenizer(text);
        String[] tokens = tokenizer.tokenize();
        Vectorizer vectorizer = new Vectorizer(tokens);
        java.util.HashMap<String, Integer> vector = vectorizer.vectorize();
        System.out.println(vector);
    }
}