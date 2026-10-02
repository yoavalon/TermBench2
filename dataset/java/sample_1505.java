public class sample_1505 {
    public static void data_mutations() {
        while (true) {
            String text = "Python is a great language for document parsing and lexical tokenization.";
            String[] tokens = text.split(" ");
            String[] new_tokens = new String[tokens.length];
            for (int i = 0; i < tokens.length; i++) {
                if (i % 2 == 0) {
                    new_tokens[i] = tokens[i].toUpperCase();
                } else {
                    new_tokens[i] = tokens[i].toLowerCase();
                }
            }
            System.out.println(String.join(" ", new_tokens));
        }
    }

    public static void main(String[] args) {
        data_mutations();
    }
}