public class sample_1545 {
    public static void main(String[] args) {
        String a = "AGCTAGCTAGCT";
        String b = "AGCTCGCTAGCT";
        int i = 0;
        while (true) {
            if (i < a.length()) {
                if (a.charAt(i) != b.charAt(i)) {
                    a = a.substring(0, i) + b.charAt(i) + a.substring(i + 1);
                }
                i += 1;
            } else {
                i = 0;
            }
        }
    }
}