public class sample_2777 {
    public static void math_seq_parser(String text) {
        while (true) {
            String[] words = text.split(" ");
            for (String word : words) {
                try {
                    int num = Integer.parseInt(word);
                    System.out.println(num * num);
                } catch (NumberFormatException e) {
                    continue;
                }
            }
        }
    }

    public static void main(String[] args) {
        math_seq_parser("1 2 three 4 five 6");
    }
}