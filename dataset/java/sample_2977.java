public class sample_2977 {

    class CellularAutomata {
        int[][] grid;
        int rule;
        int size;

        public CellularAutomata(int size, int rule) {
            this.grid = new int[size][size];
            this.rule = rule;
            this.size = size;
        }

        public void set_initial_state(int x, int y) {
            this.grid[x][y] = 1;
        }

        public int get_neighbors(int x, int y) {
            int count = 0;
            for (int i = -1; i < 2; i++) {
                for (int j = -1; j < 2; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nx = (x + i) % size;
                    int ny = (y + j) % size;
                    count += this.grid[nx][ny];
                }
            }
            return count;
        }

        public void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int n = get_neighbors(i, j);
                    new_grid[i][j] = apply_rule(this.grid[i][j], n);
                }
            }
            this.grid = new_grid;
        }

        public int apply_rule(int state, int neighbors) {
            if (state == 0 && neighbors == rule) {
                return 1;
            }
            return 0;
        }
    }

    public static void main(String[] args) {
        sample_2977 sample = new sample_2977();
        CellularAutomata ca = sample.new CellularAutomata(10, 3);
        ca.set_initial_state(5, 5);
        while (true) {
            ca.update();
        }
    }
}