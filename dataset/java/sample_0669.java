public class sample_0669 {
    public static String process_text(String text, int depth, int max_depth) {
        if (depth >= max_depth) {
            return text;
        }
        String[] words = text.split(" ");
        String[] processed_words = new String[words.length];
        for (int i = 0; i < words.length; i++) {
            processed_words[i] = words[i].toLowerCase();
        }
        return String.join(" ", processed_words) + " " + process_text(text, depth + 1, max_depth);
    }

    public static void main(String[] args) {
        String input_text = "Hello World! This is a Test.";
        String result = process_text(input_text, 0, 5);
        System.out.println(result);
    }
}