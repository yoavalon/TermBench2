public class sample_2908 {

    int[][] grid;
    int size;

    public sample_2908(int size) {
        this.grid = new int[size][size];
        this.size = size;
    }

    public void update() {
        int[][] new_grid = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int neighbors = count_neighbors(i, j);
                if (grid[i][j] == 0 && neighbors == 3) {
                    new_grid[i][j] = 1;
                } else if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }
        grid = new_grid;
    }

    public int count_neighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                    count += grid[nx][ny];
                }
            }
        }
        return count;
    }

    public void display() {
        for (int[] row : grid) {
            for (int cell : row) {
                System.out.print(cell == 1 ? '#' : ' ');
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int size = 20;
        sample_2908 automata = new sample_2908(size);
        while (true) {
            automata.display();
            automata.update();
        }
    }
}