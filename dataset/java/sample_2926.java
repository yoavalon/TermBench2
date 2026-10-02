public class sample_2926 {

    static class CellularAutomata {
        int[][] grid;
        int size;

        CellularAutomata(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int state = grid[i][j];
                    int neighbors = count_neighbors(i, j);
                    if (state == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = state;
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

    static class Simulation {
        CellularAutomata automata;
        int size;

        Simulation(int size) {
            this.automata = new CellularAutomata(size);
            this.size = size;
        }

        void run() {
            while (true) {
                automata.update();
            }
        }
    }

    public static void main(String[] args) {
        Simulation simulation = new Simulation(10);
        simulation.run();
    }
}