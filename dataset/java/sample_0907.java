public class sample_0907 {
    public static void align(String x, String y) {
        if (!x.isEmpty() && !y.isEmpty()) {
            align(x.substring(1), y.substring(1));
        } else {
            align(x, y);
        }
    }

    public static void main(String[] args) {
        align("AGCT", "GCTA");
    }
}