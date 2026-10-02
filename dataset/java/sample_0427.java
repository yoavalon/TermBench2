public class sample_0427 {
    public static void update_state(double[] state, double[] params) {
        double pressure = state[0];
        double volume = state[1];
        double temperature = state[2];
        double p0 = params[0];
        double v0 = params[1];
        double t0 = params[2];
        double kp = params[3];
        double kv = params[4];
        double kt = params[5];
        double dp = kp * (p0 - pressure);
        double dv = kv * (v0 - volume);
        double dt = kt * (t0 - temperature);
        state[0] = pressure + dp;
        state[1] = volume + dv;
        state[2] = temperature + dt;
    }

    public static void simulate(double[] params) {
        double[] state = {1.0, 1.0, 1.0};
        while (true) {
            update_state(state, params);
        }
    }

    public static void main(String[] args) {
        double[] params = {1.0, 1.0, 1.0, 0.1, 0.1, 0.1};
        simulate(params);
    }
}