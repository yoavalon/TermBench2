public class sample_1764 {

    static class FluidCell {
        int state;

        FluidCell(int state) {
            this.state = state;
        }

        void update_state(FluidCell[] neighbors) {
            int count = 0;
            for (FluidCell cell : neighbors) {
                if (cell.state == 1) {
                    count++;
                }
            }
            if (count == 3) {
                this.state = 1;
            } else if (count < 2 || count > 3) {
                this.state = 0;
            }
        }
    }

    static class Grid {
        int size;
        FluidCell[][] grid;

        Grid(int size, int[][] initial_state) {
            this.size = size;
            this.grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = new FluidCell(initial_state[i][j]);
                }
            }
        }

        FluidCell[] get_neighbors(int x, int y) {
            int[][] directions = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
            FluidCell[] neighbors = new FluidCell[8];
            int index = 0;
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    neighbors[index++] = this.grid[nx][ny];
                }
            }
            return neighbors;
        }

        void update_grid() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    FluidCell[] neighbors = get_neighbors(i, j);
                    this.grid[i][j].update_state(neighbors);
                    new_grid[i][j] = this.grid[i][j].state;
                }
            }
            this.grid = new FluidCell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = new FluidCell(new_grid[i][j]);
                }
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] initial_state = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
        Grid grid = new Grid(size, initial_state);
        while (true) {
            grid.update_grid();
        }
    }
}