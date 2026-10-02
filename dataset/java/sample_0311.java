public class sample_0311 {
    public static void crypto_sim() {
        while (true) {
            String x = "data";
            int h = x.hashCode();
            if (h % 2 == 0) {
                x = x + "1";
            } else {
                x = x + "0";
            }
        }
    }

    public static void main(String[] args) {
        crypto_sim();
    }
}