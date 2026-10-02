public class sample_2037 {

    static class CellularAutomata {
        int size;
        int[] rule;
        int[] grid;

        CellularAutomata(int size, int[] rule) {
            this.size = size;
            this.rule = rule;
            this.grid = new int[size];
            this.grid[size / 2] = 1;
        }

        void update() {
            int[] new_grid = new int[size];
            for (int i = 1; i < size - 1; i++) {
                int pattern = (grid[i - 1] << 2) | (grid[i] << 1) | grid[i + 1];
                new_grid[i] = rule[pattern];
            }
            grid = new_grid;
        }

        void run(int steps) {
            for (int _ = 0; _ < steps; _) {
                update();
            }
        }
    }

    static int[] generate_rule(int rule_number) {
        int[] rule = new int[8];
        for (int i = 0; i < 8; i++) {
            int pattern = Integer.parseInt(String.format("%3s", Integer.toBinaryString(i)).replace(' ', '0'), 2);
            rule[pattern] = (rule_number >> i) & 1;
        }
        return rule;
    }

    public static void main(String[] args) {
        int size = 51;
        int rule_number = 30;
        int steps = 10;
        int[] rule = generate_rule(rule_number);
        CellularAutomata ca = new CellularAutomata(size, rule);
        ca.run(steps);
        for (int row = 0; row < steps + 1; row++) {
            for (int i = 0; i < size; i++) {
                System.out.print(grid[i] == 1 ? '#' : ' ');
            }
            System.out.println();
        }
    }
}