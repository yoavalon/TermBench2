import java.util.ArrayList;
import java.util.List;

class FluidCell {
    int state;

    FluidCell(int state) {
        this.state = state;
    }

    void update(List<FluidCell> neighbors) {
        int sum = 0;
        for (FluidCell n : neighbors) {
            sum += n.state;
        }
        this.state = sum / neighbors.size();
    }
}

class Grid {
    int size;
    FluidCell[][] cells;

    Grid(int size) {
        this.size = size;
        this.cells = new FluidCell[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cells[i][j] = new FluidCell(0);
            }
        }
    }

    List<FluidCell> getNeighbors(int x, int y) {
        int[][] directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        List<FluidCell> neighbors = new ArrayList<>();
        for (int[] dir : directions) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors.add(cells[nx][ny]);
            }
        }
        return neighbors;
    }

    void update() {
        FluidCell[][] newGrid = new FluidCell[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                List<FluidCell> neighbors = getNeighbors(i, j);
                newGrid[i][j] = new FluidCell(0);
                newGrid[i][j].update(neighbors);
            }
        }
        cells = newGrid;
    }
}

class Simulation {
    Grid grid;
    int steps;

    Simulation(int gridSize, int steps) {
        this.grid = new Grid(gridSize);
        this.steps = steps;
    }

    void run() {
        for (int i = 0; i < steps; i++) {
            grid.update();
        }
    }
}

public class sample_0254 {
    public static void main(String[] args) {
        Simulation simulation = new Simulation(10, 50);
        simulation.run();
    }
}