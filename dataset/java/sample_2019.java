import java.util.Random;

public class sample_2019 {

    static class Automaton {
        int[][] grid;
        int[] rules;

        Automaton(int size, int[] rules) {
            this.grid = new int[size][size];
            Random random = new Random();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = random.nextInt(2);
                }
            }
            this.rules = rules;
        }

        void applyRules() {
            int[][] newGrid = new int[grid.length][grid[0].length];
            for (int i = 1; i < grid.length - 1; i++) {
                for (int j = 1; j < grid[i].length - 1; j++) {
                    int total = 0;
                    for (int x = -1; x <= 1; x++) {
                        for (int y = -1; y <= 1; y++) {
                            total += grid[i + x][j + y];
                        }
                    }
                    for (int rule : rules) {
                        if (total == rule) {
                            newGrid[i][j] = 1;
                            break;
                        }
                    }
                }
            }
            this.grid = newGrid;
        }

        void update() {
            applyRules();
        }
    }

    static class Simulation {
        Automaton automaton;
        int steps;

        Simulation(int size, int[] rules, int steps) {
            this.automaton = new Automaton(size, rules);
            this.steps = steps;
        }

        void run() {
            for (int i = 0; i < steps; i++) {
                automaton.update();
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[] rules = {3, 12};
        int steps = 50;
        Simulation simulation = new Simulation(size, rules, steps);
        simulation.run();
    }
}