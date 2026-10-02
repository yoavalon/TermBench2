import java.util.Random;

public class sample_2911 {

    static class AutomatonCell {
        int state;

        AutomatonCell(int state) {
            this.state = state;
        }

        void update_state(AutomatonCell[] neighbors) {
            int alive_neighbors = 0;
            for (AutomatonCell cell : neighbors) {
                if (cell.state == 1) {
                    alive_neighbors++;
                }
            }
            if (this.state == 1) {
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    this.state = 0;
                }
            } else if (alive_neighbors == 3) {
                this.state = 1;
            }
        }
    }

    static class AutomatonGrid {
        AutomatonCell[][] grid;
        Random random = new Random();

        AutomatonGrid(int size) {
            grid = new AutomatonCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    grid[i][j] = new AutomatonCell(random.nextInt(2));
                }
            }
        }

        AutomatonCell[] get_neighbors(int x, int y) {
            int size = grid.length;
            AutomatonCell[] neighbors = new AutomatonCell[8];
            int index = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                        neighbors[index++] = grid[nx][ny];
                    }
                }
            }
            return neighbors;
        }

        void update_grid() {
            int size = grid.length;
            AutomatonCell[][] new_grid = new AutomatonCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_grid[i][j] = new AutomatonCell(0);
                    AutomatonCell[] neighbors = get_neighbors(i, j);
                    new_grid[i][j].update_state(neighbors);
                }
            }
            grid = new_grid;
        }
    }

    public static void simulate() {
        int size = 50;
        AutomatonGrid grid = new AutomatonGrid(size);
        while (true) {
            grid.update_grid();
        }
    }

    public static void main(String[] args) {
        simulate();
    }
}