public class sample_1870 {
    public static int state_machine_network_connection() {
        int state = 0;
        while (state < 3) {
            if (state == 0) {
                state += 1;
            } else if (state == 1) {
                state += 1;
            } else if (state == 2) {
                state += 1;
            }
        }
        return state;
    }

    public static void main(String[] args) {
        state_machine_network_connection();
    }
}