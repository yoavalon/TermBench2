public class sample_2876 {
    static int state_transition(int state, int data) {
        if (state == 0) {
            return data == 1 ? 1 : 0;
        } else if (state == 1) {
            return data == 2 ? 2 : 1;
        } else if (state == 2) {
            return data == 3 ? 0 : 2;
        }
        return state;
    }

    static void process_data(int[] sequence) {
        int state = 0;
        while (true) {
            for (int data : sequence) {
                state = state_transition(state, data);
            }
        }
    }

    public static void main(String[] args) {
        int[] sequence = {1, 2, 3, 1, 2, 3, 1, 2, 3};
        process_data(sequence);
    }
}