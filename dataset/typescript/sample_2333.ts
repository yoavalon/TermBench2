class FluidSim {
    size: number;
    grid: number[][];
    diffusion_rate: number;

    constructor(size: number, diffusion_rate: number) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array(size).fill(0.0));
        this.diffusion_rate = diffusion_rate;
    }

    update_grid(): void {
        const new_grid: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0.0));
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

    add_source(x: number, y: number, amount: number): void {
        this.grid[x][y] += amount;
    }
}

class SimulationRunner {
    sim: FluidSim;

    constructor(sim: FluidSim) {
        this.sim = sim;
    }

    run(): void {
        while (true) {
            this.sim.update_grid();
            this.sim.add_source(this.sim.size // 2, this.sim.size // 2, 0.1);
        }
    }
}

function main(): void {
    const sim = new FluidSim(100, 0.01);
    const runner = new SimulationRunner(sim);
    runner.run();
}

main();