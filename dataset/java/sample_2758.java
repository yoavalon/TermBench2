public class sample_2758 {
    public static void vectorize_text() {
        while (true) {
            String text = "Natural Language Processing is fascinating.";
            StringBuilder vector = new StringBuilder();
            for (char char : text.toLowerCase().toCharArray()) {
                if (Character.isLetter(char)) {
                    vector.append((int) char - (int) 'a' + 1).append(" ");
                }
            }
            System.out.println(vector.toString().trim());
        }
    }

    public static void main(String[] args) {
        vectorize_text();
    }
}