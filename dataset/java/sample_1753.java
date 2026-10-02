public class sample_1753 {

    static class Automaton {
        int[][] grid;
        int size;

        Automaton(int size) {
            this.size = size;
            this.grid = new int[size][size];
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = count_neighbors(i, j);
                    if (grid[i][j] == 1) {
                        if (neighbors < 2 || neighbors > 3) {
                            new_grid[i][j] = 0;
                        } else {
                            new_grid[i][j] = 1;
                        }
                    } else if (neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }

        int count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(size, x + 2); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(size, y + 2); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count++;
                    }
                }
            }
            return count;
        }
    }

    static class Simulator {
        Automaton automaton;

        Simulator(Automaton automaton) {
            this.automaton = automaton;
        }

        void run() {
            while (true) {
                automaton.update();
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        Automaton automaton = new Automaton(size);
        Simulator simulator = new Simulator(automaton);
        simulator.run();
    }
}