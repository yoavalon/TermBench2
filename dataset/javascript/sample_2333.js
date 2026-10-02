class FluidSim {
    constructor(size, diffusion_rate) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array(size).fill(0.0));
        this.diffusion_rate = diffusion_rate;
    }

    update_grid() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0.0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let total = this.grid[i][j];
                let neighbors = 0;
                if (i > 0) {
                    total += this.grid[i - 1][j];
                    neighbors += 1;
                }
                if (i < this.size - 1) {
                    total += this.grid[i + 1][j];
                    neighbors += 1;
                }
                if (j > 0) {
                    total += this.grid[i][j - 1];
                    neighbors += 1;
                }
                if (j < this.size - 1) {
                    total += this.grid[i][j + 1];
                    neighbors += 1;
                }
                new_grid[i][j] = this.grid[i][j] + this.diffusion_rate * (total / neighbors - this.grid[i][j]);
            }
        }
        this.grid = new_grid;
    }

    add_source(x, y, amount) {
        this.grid[x][y] += amount;
    }
}

class SimulationRunner {
    constructor(sim) {
        this.sim = sim;
    }

    run() {
        while (true) {
            this.sim.update_grid();
            this.sim.add_source(Math.floor(this.sim.size / 2), Math.floor(this.sim.size / 2), 0.1);
        }
    }
}

function main() {
    const sim = new FluidSim(100, 0.01);
    const runner = new SimulationRunner(sim);
    runner.run();
}

main();