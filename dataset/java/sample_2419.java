import java.util.ArrayList;
import java.util.List;

public class sample_2419 {
    public static List<List<Integer>> cellular_automata(List<List<Integer>> grid, int steps) {
        for (int _ = 0; _ < steps; _++) {
            List<List<Integer>> new_grid = new ArrayList<>();
            for (int i = 0; i < grid.size(); i++) {
                new_grid.add(new ArrayList<>());
                for (int j = 0; j < grid.get(0).size(); j++) {
                    int neighbors = 0;
                    for (int[] direction : new int[][]{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}) {
                        int x = i + direction[0];
                        int y = j + direction[1];
                        if (x >= 0 && x < grid.size() && y >= 0 && y < grid.get(0).size()) {
                            neighbors += grid.get(x).get(y);
                        }
                    }
                    new_grid.get(i).add((neighbors == 2 || (neighbors == 3 && grid.get(i).get(j) == 1)) ? 1 : 0);
                }
            }
            grid = new_grid;
        }
        return grid;
    }

    public static void main(String[] args) {
        List<List<Integer>> initial_grid = new ArrayList<>();
        initial_grid.add(List.of(0, 1, 0));
        initial_grid.add(List.of(0, 1, 0));
        initial_grid.add(List.of(0, 1, 0));
        int steps = 5;
        List<List<Integer>> result = cellular_automata(initial_grid, steps);
        System.out.println(result);
    }
}