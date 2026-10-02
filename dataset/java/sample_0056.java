public class sample_0056 {
    public static void state_machine() {
        int state = 0;
        while (state < 3) {
            if (state == 0) {
                state += 1;
            } else if (state == 1) {
                state += 1;
            } else if (state == 2) {
                break;
            }
        }
    }

    public static void main(String[] args) {
        state_machine();
    }
}