class FluidSimulator {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0.0));
        this.size = size;
    }

    update(): void {
        const new_grid: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0.0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                new_grid[i][j] = this.grid[i][j] + this.calculate_flow(i, j);
            }
        }
        this.grid = new_grid;
    }

    calculate_flow(x: number, y: number): number {
        let flow = 0.0;
        for (let dx of [-1, 0, 1]) {
            for (let dy of [-1, 0, 1]) {
                if (dx === 0 && dy === 0) {
                    continue;
                }
                const nx = x + dx;
                const ny = y + dy;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    flow += this.grid[nx][ny] * 0.1;
                }
            }
        }
        return flow;
    }
}

class FluidController {
    simulator: FluidSimulator;

    constructor(simulator: FluidSimulator) {
        this.simulator = simulator;
    }

    run(): void {
        while (true) {
            this.simulator.update();
        }
    }
}

function main(): void {
    const size = 10;
    const simulator = new FluidSimulator(size);
    const controller = new FluidController(simulator);
    controller.run();
}

main();