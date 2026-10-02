public class sample_1327 {
    public static void main(String[] args) {
        int initial_temp = 300;
        int initial_press = 1;
        int initial_volume = 10;
        double mutation_factor = 1.2;
        int[] state = generate_state(initial_temp, initial_press, initial_volume);
        int energy = state[0];
        int entropy = state[1];
        int[] mutated_state = mutate_state(energy, entropy, mutation_factor);
        int mutated_energy = mutated_state[0];
        int mutated_entropy = mutated_state[1];
        System.out.println("Initial Energy: " + energy + " Initial Entropy: " + entropy);
        System.out.println("Mutated Energy: " + mutated_energy + " Mutated Entropy: " + mutated_entropy);
    }

    public static int[] generate_state(int temp, int press, int volume) {
        int energy = temp * volume;
        int entropy = press / volume;
        return new int[]{energy, entropy};
    }

    public static int[] mutate_state(int energy, int entropy, double factor) {
        int new_energy = (int) (energy * factor);
        int new_entropy = (int) (entropy * factor);
        return new int[]{new_energy, new_entropy};
    }
}