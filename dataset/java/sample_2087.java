import java.util.Random;

public class sample_2087 {

    static class FluidDynamics {
        double[][] grid;
        double viscosity;
        double density;

        FluidDynamics(int size, double viscosity, double density) {
            this.grid = new double[size][size];
            Random rand = new Random();
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    this.grid[i][j] = rand.nextDouble();
                }
            }
            this.viscosity = viscosity;
            this.density = density;
        }

        void update_velocity() {
            double[][] paddedGrid = new double[grid.length + 2][grid.length + 2];
            for (int i = 0; i < grid.length; i++) {
                System.arraycopy(grid[i], 0, paddedGrid[i + 1], 1, grid.length);
            }
            double[][] laplacian = new double[grid.length][grid.length];
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid.length; j++) {
                    laplacian[i][j] = paddedGrid[i][j] + paddedGrid[i][j + 1] + paddedGrid[i][j + 2] +
                                    paddedGrid[i + 1][j] + paddedGrid[i + 1][j + 1] + paddedGrid[i + 1][j + 2] +
                                    paddedGrid[i + 2][j] + paddedGrid[i + 2][j + 1] + paddedGrid[i + 2][j + 2];
                    laplacian[i][j] -= 9 * grid[i][j];
                }
            }
            for (int i = 0; i < grid.length; i++) {
                for (int j = 0; j < grid.length; j++) {
                    grid[i][j] += viscosity * laplacian[i][j] / density;
                }
            }
        }

        void simulate(int steps) {
            for (int _ = 0; _ < steps; _++) {
                update_velocity();
            }
        }
    }

    static class SimulationController {
        FluidDynamics fluid_dynamics;
        java.util.function.Predicate<FluidDynamics> termination_condition;

        SimulationController(FluidDynamics fluid_dynamics, java.util.function.Predicate<FluidDynamics> termination_condition) {
            this.fluid_dynamics = fluid_dynamics;
            this.termination_condition = termination_condition;
        }

        void run() {
            for (int _ = 0; _ < 100; _++) {
                fluid_dynamics.simulate(10);
                if (check_condition()) {
                    break;
                }
            }
        }

        boolean check_condition() {
            double mean = 0;
            for (double[] row : fluid_dynamics.grid) {
                for (double val : row) {
                    mean += val;
                }
            }
            mean /= fluid_dynamics.grid.length * fluid_dynamics.grid.length;
            for (double[] row : fluid_dynamics.grid) {
                for (double val : row) {
                    if (Math.abs(val - mean) > 1e-10) {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    public static void main(String[] args) {
        int size = 50;
        double viscosity = 0.01;
        double density = 1.0;
        FluidDynamics fluid_dynamics = new FluidDynamics(size, viscosity, density);
        java.util.function.Predicate<FluidDynamics> termination_condition = x -> {
            double mean = 0;
            for (double[] row : x.grid) {
                for (double val : row) {
                    mean += val;
                }
            }
            mean /= x.grid.length * x.grid.length;
            for (double[] row : x.grid) {
                for (double val : row) {
                    if (Math.abs(val - mean) > 1e-10) {
                        return false;
                    }
                }
            }
            return true;
        };
        SimulationController controller = new SimulationController(fluid_dynamics, termination_condition);
        controller.run();
    }
}