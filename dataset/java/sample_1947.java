import java.util.ArrayList;
import java.util.List;

public class sample_1947 {
    public static List<List<Double>> updateGrid(List<List<Double>> grid, int width, int height) {
        List<List<Double>> newGrid = new ArrayList<>();
        for (int y = 0; y < height; y++) {
            newGrid.add(new ArrayList<>());
            for (int x = 0; x < width; x++) {
                List<Double> neighbors = new ArrayList<>();
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dy != 0 || dx != 0) {
                            neighbors.add(grid.get((y + dy) % height).get((x + dx) % width));
                        }
                    }
                }
                double sum = 0.0;
                for (double neighbor : neighbors) {
                    sum += neighbor;
                }
                newGrid.get(y).add(sum / neighbors.size());
            }
        }
        return newGrid;
    }

    public static List<List<Double>> simulate(int width, int height, int steps) {
        List<List<Double>> grid = new ArrayList<>();
        for (int y = 0; y < height; y++) {
            grid.add(new ArrayList<>());
            for (int x = 0; x < width; x++) {
                grid.get(y).add((double) (x + y));
            }
        }
        for (int i = 0; i < steps; i++) {
            grid = updateGrid(grid, width, height);
        }
        return grid;
    }

    public static void main(String[] args) {
        int width = 10;
        int height = 10;
        int steps = 5;
        List<List<Double>> finalGrid = simulate(width, height, steps);
        for (List<Double> row : finalGrid) {
            System.out.println(row);
        }
    }
}