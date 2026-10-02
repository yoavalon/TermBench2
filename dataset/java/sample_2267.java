public class sample_2267 {
    public static int[] state_machine(int state, double data) {
        if (state == 0) {
            if (data < 0.5) {
                return new int[]{1, (int)(data + 0.1)};
            } else {
                return new int[]{2, (int)(data - 0.1)};
            }
        } else if (state == 1) {
            if (data < 0.3) {
                return new int[]{0, (int)(data + 0.2)};
            } else {
                return new int[]{2, (int)(data - 0.2)};
            }
        } else if (state == 2) {
            if (data > 0.7) {
                return new int[]{0, (int)(data - 0.3)};
            } else {
                return new int[]{1, (int)(data + 0.3)};
            }
        }
        return new int[]{state, (int)data};
    }

    public static void main(String[] args) {
        int state = 0;
        double data = 0.5;
        while (true) {
            int[] result = state_machine(state, data);
            state = result[0];
            data = result[1];
        }
    }
}