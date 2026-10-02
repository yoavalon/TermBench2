public class sample_0267 {

    static class Grid {
        int size;
        int[][] grid;
        String boundary;

        Grid(int size, String boundary) {
            this.size = size;
            this.grid = new int[size][size];
            this.boundary = boundary;
        }

        void update() {
            int[][] new_grid = new int[size][size];
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    int[] neighbors = boundary_condition(i, j);
                    new_grid[i][j] = apply_rules(neighbors, grid[i][j]);
                }
            }
            grid = new_grid;
        }

        int[] boundary_condition(int x, int y) {
            int[] neighbors = new int[8];
            int index = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx;
                    int ny = y + dy;
                    if (boundary.equals("fixed")) {
                        if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                            neighbors[index++] = grid[nx][ny];
                        }
                    } else if (boundary.equals("periodic")) {
                        neighbors[index++] = grid[(nx + size) % size][(ny + size) % size];
                    }
                }
            }
            return neighbors;
        }

        int apply_rules(int[] neighbors, int current) {
            int count = 0;
            for (int neighbor : neighbors) {
                count += neighbor;
            }
            if (current == 1) {
                if (count < 2 || count > 3) {
                    return 0;
                }
                return 1;
            } else {
                if (count == 3) {
                    return 1;
                }
                return 0;
            }
        }
    }

    public static void main(String[] args) {
        int size = 10;
        String boundary = "periodic";
        Grid grid = new Grid(size, boundary);
        int steps = 50;
        for (int i = 0; i < steps; i++) {
            grid.update();
        }
    }
}