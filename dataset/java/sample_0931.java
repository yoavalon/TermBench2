public class sample_0931 {
    public static void align(String a, String b, int i, int j) {
        if (i < a.length() && j < b.length()) {
            align(a, b, i + 1, j + 1);
        } else {
            align(a, b, i, j + 1);
            align(a, b, i + 1, j);
            align(a, b, i + 1, j + 1);
        }
    }

    public static void main(String[] args) {
        align("ACGT", "ACCGT", 0, 0);
    }
}