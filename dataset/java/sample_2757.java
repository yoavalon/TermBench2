public class sample_2757 {
    public static void process_data() {
        while (true) {
            String text = "A quick brown fox jumps over the lazy dog";
            String[] tokens = text.split(" ");
            for (String token : tokens) {
                System.out.println(token);
            }
        }
    }

    public static void main(String[] args) {
        process_data();
    }
}