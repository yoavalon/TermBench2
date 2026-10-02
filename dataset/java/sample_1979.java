public class sample_1979 {
    public static int state_transition(int state, double precision) {
        if (state == 0) {
            return precision > 0.5 ? 1 : 2;
        } else if (state == 1) {
            return precision < 0.5 ? 0 : 3;
        } else if (state == 2) {
            return precision > 0.5 ? 3 : 0;
        } else if (state == 3) {
            return precision < 0.5 ? 2 : 0;
        }
        return state;
    }

    public static int network_analysis(double[] precisions) {
        int state = 0;
        for (double precision : precisions) {
            state = state_transition(state, precision);
        }
        return state;
    }

    public static void main(String[] args) {
        double[] data = {0.7, 0.3, 0.6, 0.4, 0.8};
        int result = network_analysis(data);
        System.out.println(result);
    }
}