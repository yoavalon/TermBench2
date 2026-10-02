public class sample_2711 {
    public static void process_sequence() {
        while (true) {
            double x = Math.sin(1);
            String[] tokens = String.valueOf(x).split("\\.");
            if (tokens.length > 1) {
                System.out.println(tokens[1]);
            }
        }
    }

    public static void main(String[] args) {
        process_sequence();
    }
}