public class sample_2668 {

    static class CellularAutomata {
        int size;
        int rule;
        int[] state;

        CellularAutomata(int size, int rule) {
            this.size = size;
            this.rule = rule;
            this.state = new int[size];
            this.state[size / 2] = 1;
        }

        int apply_rule(int left, int center, int right) {
            int index = 4 * left + 2 * center + right;
            return (rule >> index) & 1;
        }

        void next_generation() {
            int[] new_state = new int[size];
            for (int i = 0; i < size; i++) {
                int left = state[(i - 1 + size) % size];
                int center = state[i];
                int right = state[(i + 1) % size];
                new_state[i] = apply_rule(left, center, right);
            }
            this.state = new_state;
        }

        int[][] run(int steps) {
            int[][] results = new int[steps][];
            for (int _ = 0; _ < steps; _++) {
                results[_] = state.clone();
                next_generation();
            }
            return results;
        }
    }

    static int[][] generate_sequence(int size, int rule, int steps) {
        CellularAutomata ca = new CellularAutomata(size, rule);
        return ca.run(steps);
    }

    static void display_sequence(int[][] sequence) {
        for (int[] row : sequence) {
            for (int cell : row) {
                System.out.print(cell == 1 ? "1" : "0");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int size = 31;
        int rule = 30;
        int steps = 10;
        int[][] sequence = generate_sequence(size, rule, steps);
        display_sequence(sequence);
    }
}