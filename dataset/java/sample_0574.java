public class sample_0574 {
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
            if (this.state == 1 && (live_neighbors < 2 || live_neighbors > 3)) {
                this.state = 0;
            } else if (this.state == 0 && live_neighbors == 3) {
                this.state = 1;
            }
        }
    }

    static class Grid {
        int size;
        Cell[][] cells;

        Grid(int size, int[][] initial_state) {
            this.size = size;
            this.cells = new Cell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.cells[i][j] = new Cell(initial_state[i][j]);
                }
            }
        }

        Cell[] get_neighbors(int x, int y) {
            Cell[] neighbors = new Cell[8];
            int index = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nx = x + i;
                    int ny = y + j;
                    if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                        neighbors[index++] = this.cells[nx][ny];
                    } else {
                        neighbors[index++] = new Cell(0);
                    }
                }
            }
            return neighbors;
        }

        void update() {
            Cell[][] new_cells = new Cell[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    new_cells[i][j] = new Cell(this.cells[i][j].state);
                }
            }
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    Cell[] neighbors = get_neighbors(i, j);
                    new_cells[i][j].update(neighbors);
                }
            }
            this.cells = new_cells;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        int[][] initial_state = new int[size][size];
        initial_state[4][4] = 1;
        initial_state[4][5] = 1;
        initial_state[5][4] = 1;
        initial_state[5][5] = 1;
        Grid grid = new Grid(size, initial_state);
        while (true) {
            grid.update();
        }
    }
}