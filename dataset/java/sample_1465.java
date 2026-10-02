public class sample_1465 {

    class CellularAutomata {
        int[][] grid;
        int size;

        public CellularAutomata(int size) {
            this.grid = new int[size][size];
            this.size = size;
        }

        public void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int neighbors = _count_neighbors(i, j);
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
            this.grid = new_grid;
        }

        private int _count_neighbors(int x, int y) {
            int count = 0;
            for (int i = Math.max(0, x - 1); i < Math.min(x + 2, size); i++) {
                for (int j = Math.max(0, y - 1); j < Math.min(y + 2, size); j++) {
                    if ((i != x || j != y) && grid[i][j] == 1) {
                        count += 1;
                    }
                }
            }
            return count;
        }
    }

    public static void main(String[] args) {
        int size = 10;
        sample_1465 outer = new sample_1465();
        CellularAutomata ca = outer.new CellularAutomata(size);
        for (int _ = 0; _ < 100; _++) {
            ca.update();
        }
        for (int[] row : ca.grid) {
            StringBuilder sb = new StringBuilder();
            for (int cell : row) {
                sb.append(cell == 1 ? '*' : ' ');
            }
            System.out.println(sb.toString());
        }
    }
}