public class sample_1067 {
    public static void state_a(int x) {
        if (x % 2 == 0) {
            state_b(x + 1);
        } else {
            state_c(x + 1);
        }
    }

    public static void state_b(int x) {
        if (x % 3 == 0) {
            state_a(x + 1);
        } else {
            state_c(x + 1);
        }
    }

    public static void state_c(int x) {
        if (x % 5 == 0) {
            state_a(x + 1);
        } else {
            state_b(x + 1);
        }
    }

    public static void main(String[] args) {
        state_a(1);
    }
}