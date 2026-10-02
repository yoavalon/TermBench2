const { random } = require('mathjs');

class FluidDynamics {
    constructor(size, viscosity, density) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0).map(() => random()));
        this.viscosity = viscosity;
        this.density = density;
    }

    updateVelocity() {
        const size = this.grid.length;
        const paddedGrid = Array.from({ length: size + 2 }, () => Array(size + 2).fill(0));
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                paddedGrid[i + 1][j + 1] = this.grid[i][j];
            }
        }

        let laplacian = 0;
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                laplacian = paddedGrid[i][j] + paddedGrid[i + 2][j] + paddedGrid[i][j + 2] + paddedGrid[i + 2][j + 2] +
                           paddedGrid[i][j + 1] + paddedGrid[i + 2][j + 1] + paddedGrid[i + 1][j] + paddedGrid[i + 1][j + 2];
                laplacian -= 9 * this.grid[i][j];
                this.grid[i][j] += (this.viscosity * laplacian) / this.density;
            }
        }
    }

    simulate(steps) {
        for (let _ = 0; _ < steps; _++) {
            this.updateVelocity();
        }
    }
}

class SimulationController {
    constructor(fluidDynamics, terminationCondition) {
        this.fluidDynamics = fluidDynamics;
        this.terminationCondition = terminationCondition;
    }

    run() {
        for (let _ = 0; _ < 100; _++) {
            this.fluidDynamics.simulate(10);
            if (this.checkCondition()) {
                break;
            }
        }
    }

    checkCondition() {
        const size = this.fluidDynamics.grid.length;
        const mean = this.fluidDynamics.grid.flat().reduce((a, b) => a + b, 0) / (size * size);
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                if (Math.abs(this.fluidDynamics.grid[i][j] - mean) > 1e-10) {
                    return false;
                }
            }
        }
        return true;
    }
}

function main() {
    const size = 50;
    const viscosity = 0.01;
    const density = 1.0;
    const fluidDynamics = new FluidDynamics(size, viscosity, density);
    const terminationCondition = (x) => {
        const mean = x.grid.flat().reduce((a, b) => a + b, 0) / (size * size);
        for (let i = 0; i < size; i++) {
            for (let j = 0; j < size; j++) {
                if (Math.abs(x.grid[i][j] - mean) > 1e-10) {
                    return false;
                }
            }
        }
        return true;
    };
    const controller = new SimulationController(fluidDynamics, terminationCondition);
    controller.run();
}

main();