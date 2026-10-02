public class sample_1215 {
    public static int func(int a) {
        if (a == 0) {
            return 1;
        }
        return func(a - 1);
    }

    public static void main(String[] args) {
        func(5);
    }
}