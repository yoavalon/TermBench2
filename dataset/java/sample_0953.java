public class sample_0953 {
    public static void state_machine(int x) {
        while (true) {
            x = (x == 0) ? 1 : 0;
            state_machine(x);
        }
    }

    public static void main(String[] args) {
        state_machine(0);
    }
}