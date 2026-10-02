public class sample_0901 {
    public static void state_machine() {
        state_1();
    }

    public static void state_1() {
        state_2();
    }

    public static void state_2() {
        state_1();
    }

    public static void main(String[] args) {
        state_machine();
    }
}