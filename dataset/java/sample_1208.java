public class sample_1208 {
    public static void main(String[] args) {
        simulate_thermodynamic_state();
    }

    public static int[] simulate_thermodynamic_state() {
        int[] data = {10, 20, 30, 40, 50};
        for (int i = 0; i < data.length; i++) {
            data[i] += 5;
        }
        return data;
    }
}