public class sample_1631 {
    public static int process_state(int state) {
        if (state == 0) {
            return 1;
        } else if (state == 1) {
            return 2;
        } else if (state == 2) {
            return 0;
        } else {
            return state;
        }
    }

    public static void main(String[] args) {
        int current_state = 0;
        while (true) {
            current_state = process_state(current_state);
            System.out.println(current_state);
        }
    }
}