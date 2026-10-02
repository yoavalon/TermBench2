import * as math from 'mathjs';

class FluidDynamics {
    grid: number[][];
    viscosity: number;
    density: number;

    constructor(size: number, viscosity: number, density: number) {
        this.grid = Array.from({ length: size }, () => Array.from({ length: size }, () => Math.random()));
        this.viscosity = viscosity;
        this.density = density;
    }

    update_velocity() {
        const size = this.grid.length;
        const paddedGrid = Array.from({ length: size + 2 }, () => Array.from({ length: size + 2 }, () => 0));
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                paddedGrid[i + 1][j + 1] = this.grid[i][j];
            }
        }
        const laplacian = Array.from({ length: size }, () => Array.from({ length: size }, () => 0));
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                laplacian[i][j] = paddedGrid[i][j] + paddedGrid[i + 1][j] + paddedGrid[i + 2][j] +
                                 paddedGrid[i][j + 1] + paddedGrid[i + 1][j + 1] + paddedGrid[i + 2][j + 1] +
                                 paddedGrid[i][j + 2] + paddedGrid[i + 1][j + 2] + paddedGrid[i + 2][j + 2];
                laplacian[i][j] -= 9 * this.grid[i][j];
            }
        }
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                this.grid[i][j] += this.viscosity * laplacian[i][j] / this.density;
            }
        }
    }

    simulate(steps: number) {
        for (let _ = 0; _ < steps; _++) {
            this.update_velocity();
        }
    }
}

class SimulationController {
    fluid_dynamics: FluidDynamics;
    termination_condition: (fd: FluidDynamics) => boolean;

    constructor(fluid_dynamics: FluidDynamics, termination_condition: (fd: FluidDynamics) => boolean) {
        this.fluid_dynamics = fluid_dynamics;
        this.termination_condition = termination_condition;
    }

    run() {
        for (let _ = 0; _ < 100; _++) {
            this.fluid_dynamics.simulate(10);
            if (this.check_condition()) {
                break;
            }
        }
    }

    check_condition() {
        const meanValue = math.mean(math.flatten(this.fluid_dynamics.grid));
        const allClose = this.fluid_dynamics.grid.every(row => row.every(value => math.isCloseTo(value, meanValue)));
        return allClose;
    }
}

function main() {
    const size = 50;
    const viscosity = 0.01;
    const density = 1.0;
    const fluid_dynamics = new FluidDynamics(size, viscosity, density);
    const termination_condition = (fd: FluidDynamics) => math.allClose(math.flatten(fd.grid), math.mean(math.flatten(fd.grid)));
    const controller = new SimulationController(fluid_dynamics, termination_condition);
    controller.run();
}

main();