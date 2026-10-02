class Grid {
    grid: number[][];
    size: number;

    constructor(size: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update(rule: (center: number, neighbors: number[]) => number): void {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.get_neighbors(i, j);
                new_grid[i][j] = rule(this.grid[i][j], neighbors);
            }
        }
        this.grid = new_grid;
    }

    get_neighbors(x: number, y: number): number[] {
        const directions = [
            [-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]
        ];
        const neighbors: number[] = [];
        for (const [dx, dy] of directions) {
            const nx = x + dx;
            const ny = y + dy;
            if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                neighbors.push(this.grid[nx][ny]);
            }
        }
        return neighbors;
    }
}

class Automaton {
    grid: Grid;

    constructor(grid: Grid) {
        this.grid = grid;
    }

    run(rule: (center: number, neighbors: number[]) => number, steps: number): void {
        for (let _ = 0; _ < steps; _++) {
            this.grid.update(rule);
        }
    }
}

function simple_rule(center: number, neighbors: number[]): number {
    const live_neighbors = neighbors.reduce((acc, val) => acc + val, 0);
    if (center === 1) {
        return live_neighbors === 2 || live_neighbors === 3 ? 1 : 0;
    } else {
        return live_neighbors === 3 ? 1 : 0;
    }
}

function main(): void {
    const grid_size = 10;
    const initial_grid = new Grid(grid_size);
    initial_grid.grid[4][4] = 1;
    initial_grid.grid[5][5] = 1;
    initial_grid.grid[6][4] = 1;
    initial_grid.grid[5][3] = 1;
    initial_grid.grid[4][5] = 1;
    const automaton = new Automaton(initial_grid);
    while (true) {
        automaton.run(simple_rule, 1);
    }
}

main();