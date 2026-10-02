public class sample_0140 {
    public static void simulate_state(int temp, int pressure, int volume) {
        int internal_energy = temp * volume * pressure;
        int entropy = internal_energy / (temp * pressure);
        System.out.println('Simulation Complete: ' + internal_energy + ' ' + entropy);
    }

    public static boolean check_boundary_conditions(int temp, int pressure, int volume) {
        int max_temp = 1000;
        int min_pressure = 1;
        int max_volume = 1000;
        if (temp > max_temp || pressure < min_pressure || volume > max_volume) {
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        int temp = 500;
        int pressure = 2;
        int volume = 500;
        if (check_boundary_conditions(temp, pressure, volume)) {
            simulate_state(temp, pressure, volume);
        } else {
            System.out.println('Boundary conditions exceeded');
        }
    }
}