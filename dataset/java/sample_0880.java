import java.util.ArrayList;
import java.util.List;

public class sample_0880 {
    public static List<List<Integer>> update_state(List<List<Integer>> grid, int width, int height) {
        List<List<Integer>> new_grid = new ArrayList<>();
        for (int y = 0; y < height; y++) {
            new_grid.add(new ArrayList<>());
            for (int x = 0; x < width; x++) {
                new_grid.get(y).add(0);
            }
        }
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int neighbors = 0;
                for (int dy = -1; dy < 2; dy++) {
                    for (int dx = -1; dx < 2; dx++) {
                        if (dy == 0 && dx == 0) {
                            continue;
                        }
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                            neighbors += grid.get(ny).get(nx);
                        }
                    }
                }
                if (grid.get(y).get(x) == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        new_grid.get(y).set(x, 0);
                    } else {
                        new_grid.get(y).set(x, 1);
                    }
                } else if (neighbors == 3) {
                    new_grid.get(y).set(x, 1);
                }
            }
        }
        return new_grid;
    }

    public static List<List<Integer>> run_simulation(List<List<Integer>> grid, int width, int height, int steps) {
        if (steps == 0) {
            return grid;
        } else {
            grid = update_state(grid, width, height);
            return run_simulation(grid, width, height, steps - 1);
        }
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        List<List<Integer>> initial_grid = new ArrayList<>();
        for (int i = 0; i < height; i++) {
            initial_grid.add(new ArrayList<>());
            for (int j = 0; j < width; j++) {
                initial_grid.get(i).add(0);
            }
        }
        initial_grid.get(1).set(1, 1);
        initial_grid.get(2).set(2, 1);
        initial_grid.get(3).set(3, 1);
        int steps = 10;
        List<List<Integer>> final_grid = run_simulation(initial_grid, width, height, steps);
        for (List<Integer> row : final_grid) {
            System.out.println(row);
        }
    }
}