public class sample_1734 {
    static class CellularAutomaton {
        int[][] grid;
        int size;

        CellularAutomaton(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = _count_neighbors(i, j);
                    if (grid[i][j] == 0) {
                        if (neighbors == 3) {
                            new_grid[i][j] = 1;
                        }
                    } else if (neighbors < 2 || neighbors > 3) {
                        new_grid[i][j] = 0;
                    } else {
                        new_grid[i][j] = 1;
                    }
                }
            }
            grid = new_grid;
        }

        int _count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(x + 2, size); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(y + 2, size); j++) {
                    if ((i != x) || (j != y)) {
                        count += grid[i][j];
                    }
                }
            }
            return count;
        }
    }

    static void display(int[][] grid) {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? "█" : " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int size = 10;
        CellularAutomaton automaton = new CellularAutomaton(size);
        while (true) {
            display(automaton.grid);
            automaton.update();
        }
    }
}