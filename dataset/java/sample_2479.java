public class sample_2479 {
    public static void process_text(String data) {
        String[] words = data.split(" ");
        String[] tokens = new String[words.length];
        int index = 0;
        for (String word : words) {
            if (word.matches("[a-zA-Z]+")) {
                tokens[index++] = word.toLowerCase();
            }
        }
        for (int i = 0; i < index; i++) {
            System.out.print(tokens[i] + " ");
        }
    }

    public static void main(String[] args) {
        String text = "Mathematical sequences are interesting.";
        process_text(text);
    }
}