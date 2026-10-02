class FluidSimulator {
    size: number;
    state: number[][];

    constructor(size: number, initial_state: number[][]) {
        this.size = size;
        this.state = initial_state;
    }

    update_state(): void {
        let new_state: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let neighbors: number[] = this.get_neighbors(i, j);
                new_state[i][j] = this.apply_rules(neighbors);
            }
        }
        this.state = new_state;
    }

    get_neighbors(x: number, y: number): number[] {
        let directions: [number, number][] = [
            [-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]
        ];
        let neighbors: number[] = [];
        for (let [dx, dy] of directions) {
            let nx = x + dx;
            let ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.state[nx][ny]);
            }
        }
        return neighbors;
    }

    apply_rules(neighbors: number[]): number {
        let active_neighbors = neighbors.reduce((sum, n) => sum + n, 0);
        if (this.state[0][0] === 1) {
            return active_neighbors >= 2 ? 1 : 0;
        } else {
            return active_neighbors === 3 ? 1 : 0;
        }
    }
}

function initialize_grid(size: number): number[][] {
    return Array.from({ length: size }, (_, i) =>
        Array.from({ length: size }, (_, j) => (i % 2 && j % 2 ? 0 : 1))
    );
}

function main(): void {
    let grid_size = 10;
    let initial_state = initialize_grid(grid_size);
    let simulator = new FluidSimulator(grid_size, initial_state);
    while (true) {
        simulator.update_state();
    }
}

main();