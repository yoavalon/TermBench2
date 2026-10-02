import java.util.Arrays;

public class sample_0528 {

    static class Automaton {
        int[][] grid;
        int size;

        Automaton(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update() {
            int[][] new_grid = Arrays.copyOf(grid, size);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = grid[(i - 1 + size) % size][(j - 1 + size) % size] + grid[(i - 1 + size) % size][j] + grid[(i - 1 + size) % size][(j + 1) % size] + grid[i][(j - 1 + size) % size] + grid[i][(j + 1) % size] + grid[(i + 1) % size][(j - 1 + size) % size] + grid[(i + 1) % size][j] + grid[(i + 1) % size][(j + 1) % size];
                    if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                        new_grid[i][j] = 0;
                    } else if (grid[i][j] == 0 && neighbors == 3) {
                        new_grid[i][j] = 1;
                    }
                }
            }
            this.grid = new_grid;
        }
    }

    static class BoundaryHandler {
        Automaton automaton;

        BoundaryHandler(Automaton automaton) {
            this.automaton = automaton;
        }

        void apply_boundary_conditions() {
            for (int j = 0; j < automaton.size; j++) {
                automaton.grid[0][j] = 0;
                automaton.grid[automaton.size - 1][j] = 0;
            }
            for (int i = 0; i < automaton.size; i++) {
                automaton.grid[i][0] = 0;
                automaton.grid[i][automaton.size - 1] = 0;
            }
        }
    }

    public static void main(String[] args) {
        int size = 100;
        Automaton automaton = new Automaton(size);
        BoundaryHandler boundary_handler = new BoundaryHandler(automaton);
        automaton.grid[1][2] = 1;
        automaton.grid[2][3] = 1;
        automaton.grid[3][1] = 1;
        automaton.grid[3][2] = 1;
        automaton.grid[3][3] = 1;
        while (true) {
            boundary_handler.apply_boundary_conditions();
            automaton.update();
        }
    }
}