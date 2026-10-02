public class sample_0535 {

    static class Cell {
        int state;

        Cell(int state) {
            this.state = state;
        }

        void update(Cell[] neighbors) {
            int aliveNeighbors = 0;
            for (Cell n : neighbors) {
                if (n.state == 1) {
                    aliveNeighbors++;
                }
            }
            if (this.state == 1) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    this.state = 0;
                }
            } else if (aliveNeighbors == 3) {
                this.state = 1;
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
            this.grid = new Cell[width][height];
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    this.grid[x][y] = new Cell(initial_state[x][y]);
                }
            }
        }

        Cell[] getNeighbors(int x, int y) {
            Cell[] neighbors = new Cell[8];
            int index = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors[index++] = this.grid[nx][ny];
                    }
                }
            }
            return neighbors;
        }

        void update() {
            Cell[][] newGrid = new Cell[width][height];
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    Cell cell = this.grid[x][y];
                    Cell[] neighbors = getNeighbors(x, y);
                    newGrid[x][y] = new Cell(0);
                    newGrid[x][y].update(neighbors);
                }
            }
            this.grid = newGrid;
        }
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        int[][] initialState = {
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };
        Grid grid = new Grid(width, height, initialState);
        while (true) {
            grid.update();
        }
    }
}