public class sample_1791 {

    static class Cell {
        int state;

        Cell(int state) {
            this.state = state;
        }

        void update(Cell[] neighbors) {
            int live_neighbors = 0;
            for (Cell cell : neighbors) {
                if (cell.state == 1) {
                    live_neighbors++;
                }
            }
            if (this.state == 1) {
                this.state = (live_neighbors == 2 || live_neighbors == 3) ? 1 : 0;
            } else {
                this.state = (live_neighbors == 3) ? 1 : 0;
            }
        }
    }

    static class Grid {
        int width;
        int height;
        Cell[][] grid;

        Grid(int width, int height, int[][] initial_state) {
            this.width = width;
            this.height = height;
            this.grid = new Cell[height][width];
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    this.grid[i][j] = (initial_state != null) ? new Cell(initial_state[i][j]) : new Cell();
                }
            }
        }

        Cell[] get_neighbors(int x, int y) {
            int[][] directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
            Cell[] neighbors = new Cell[8];
            int index = 0;
            for (int[] dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                    neighbors[index++] = this.grid[ny][nx];
                }
            }
            return neighbors;
        }

        void update() {
            Cell[][] new_grid = new Cell[height][width];
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    new_grid[i][j] = new Cell(this.grid[i][j].state);
                }
            }
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    Cell[] neighbors = get_neighbors(j, i);
                    new_grid[i][j].update(neighbors);
                }
            }
            this.grid = new_grid;
        }
    }

    public static void main(String[] args) {
        int[][] initial_state = {{0, 1, 0}, {0, 1, 0}, {0, 1, 0}};
        Grid grid = new Grid(3, 3, initial_state);
        while (true) {
            grid.update();
        }
    }
}