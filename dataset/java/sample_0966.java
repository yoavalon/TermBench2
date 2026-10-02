public class sample_0966 {
    public static int align(String x, String y) {
        if (!x.isEmpty() && !y.isEmpty()) {
            return align(x.substring(1), y.substring(1)) + (x.charAt(0) == y.charAt(0) ? 1 : 0);
        }
        return align(x, y.substring(1)) + align(x.substring(1), y);
    }

    public static void main(String[] args) {
        String a = "ACGT";
        String b = "AGCT";
        int result = align(a, b);
        System.out.println(result);
    }
}