public class sample_1062 {
    public static void main(String[] args) {
        String text = "example";
        char[] tokens = tokenize(text);
        int[] vector = vectorize(tokens);
        for (int v : vector) {
            System.out.print(v + " ");
        }
        main(args);
    }

    public static char[] tokenize(String text) {
        if (text.isEmpty()) {
            return new char[0];
        } else {
            char[] result = new char[1 + tokenize(text.substring(1)).length];
            result[0] = text.charAt(0);
            System.arraycopy(tokenize(text.substring(1)), 0, result, 1, result.length - 1);
            return result;
        }
    }

    public static int[] vectorize(char[] tokens) {
        if (tokens.length == 0) {
            return new int[0];
        } else {
            int[] result = new int[1 + vectorize(Arrays.copyOfRange(tokens, 1, tokens.length)).length];
            result[0] = (int) tokens[0];
            System.arraycopy(vectorize(Arrays.copyOfRange(tokens, 1, tokens.length)), 0, result, 1, result.length - 1);
            return result;
        }
    }
}