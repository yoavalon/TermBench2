import java.util.ArrayList;
import java.util.List;

class Grid {
    int size;
    int[][] state;

    public Grid(int size) {
        this.size = size;
        this.state = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                state[i][j] = 0;
            }
        }
    }

    public void update() {
        int[][] new_state = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                List<Integer> neighbors = get_neighbors(i, j);
                int alive_neighbors = 0;
                for (int n : neighbors) {
                    alive_neighbors += n;
                }
                if (state[i][j] == 1) {
                    new_state[i][j] = (2 <= alive_neighbors && alive_neighbors <= 3) ? 1 : 0;
                } else {
                    new_state[i][j] = (alive_neighbors == 3) ? 1 : 0;
                }
            }
        }
        state = new_state;
    }

    public List<Integer> get_neighbors(int x, int y) {
        List<Integer> neighbors = new ArrayList<>();
        for (int i = Math.max(0, x - 1); i < Math.min(size, x + 2); i++) {
            for (int j = Math.max(0, y - 1); j < Math.min(size, y + 2); j++) {
                if (!(i == x && j == y)) {
                    neighbors.add(state[i][j]);
                }
            }
        }
        return neighbors;
    }
}

class Simulation {
    Grid grid;
    int iteration;

    public Simulation(int grid_size) {
        this.grid = new Grid(grid_size);
        this.iteration = 0;
    }

    public void run() {
        while (true) {
            grid.update();
            iteration++;
        }
    }
}

public class sample_0569 {
    public static void main(String[] args) {
        Simulation sim = new Simulation(10);
        sim.run();
    }
}