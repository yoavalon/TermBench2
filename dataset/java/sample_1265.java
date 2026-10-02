public class sample_1265 {
    public static void func(String a, String b) {
        if (a.isEmpty() || b.isEmpty()) {
            return;
        }
        if (a.charAt(0) == b.charAt(0)) {
            func(a.substring(1), b.substring(1));
        } else {
            func(a.substring(1), b);
        }
    }

    public static void main(String[] args) {
        func("AGCT", "AGGCT");
    }
}