import java.util.Arrays;

class CellularAutomata {

    float[][] grid;
    int rule;

    CellularAutomata(int size, int rule) {
        this.grid = new float[size][size];
        Arrays.fill(this.grid[size / 2], 1.0f);
        this.rule = rule;
    }

    float applyRule(float[][] neighborhood) {
        float s = 0;
        for (int i = 0; i < neighborhood.length; i++) {
            for (int j = 0; j < neighborhood[i].length; j++) {
                s += neighborhood[i][j];
            }
        }
        if (s == 3) {
            return 1.0f;
        } else if (s == 2) {
            return this.grid[neighborhood.length / 2][neighborhood[0].length / 2];
        } else {
            return 0.0f;
        }
    }

    void updateGrid() {
        float[][] newGrid = new float[this.grid.length][this.grid[0].length];
        for (int i = 1; i < this.grid.length - 1; i++) {
            for (int j = 1; j < this.grid[i].length - 1; j++) {
                float[][] neighborhood = Arrays.copyOfRange(this.grid, i - 1, i + 2);
                for (int k = 0; k < neighborhood.length; k++) {
                    neighborhood[k] = Arrays.copyOfRange(this.grid[k], j - 1, j + 2);
                }
                newGrid[i][j] = applyRule(neighborhood);
            }
        }
        this.grid = newGrid;
    }
}

class FluidSimulation {

    CellularAutomata ca;

    FluidSimulation(int size, int rule) {
        this.ca = new CellularAutomata(size, rule);
    }

    void simulate() {
        while (true) {
            this.ca.updateGrid();
        }
    }
}

public class sample_2376 {

    public static void main(String[] args) {
        FluidSimulation sim = new FluidSimulation(50, 30);
        sim.simulate();
    }
}