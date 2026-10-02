class CellularAutomaton {
    grid_size: number;
    rule: { survive: number[], birth: number[] };
    grid: number[][];

    constructor(grid_size: number, rule: { survive: number[], birth: number[] }) {
        this.grid_size = grid_size;
        this.rule = rule;
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.grid[grid_size // 2][grid_size // 2] = 1;
    }

    update() {
        const new_grid = Array.from({ length: this.grid_size }, () => Array(this.grid_size).fill(0));
        for (let i = 0; i < this.grid_size; i++) {
            for (let j = 0; j < this.grid_size; j++) {
                const neighbors = this.count_neighbors(i, j);
                new_grid[i][j] = this.apply_rule(this.grid[i][j], neighbors);
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = x - 1; i < x + 2; i++) {
            for (let j = y - 1; j < y + 2; j++) {
                if (i >= 0 && i < this.grid_size && j >= 0 && j < this.grid_size && !(i === x && j === y)) {
                    count += this.grid[i][j];
                }
            }
        }
        return count;
    }

    apply_rule(cell: number, neighbors: number): number {
        if (cell === 1 && this.rule.survive.includes(neighbors)) {
            return 1;
        } else if (cell === 0 && this.rule.birth.includes(neighbors)) {
            return 1;
        }
        return 0;
    }
}

function main() {
    const size = 50;
    const rule = { survive: [2, 3], birth: [3] };
    const ca = new CellularAutomaton(size, rule);
    for (let _ = 0; _ < 100; _++) {
        ca.update();
    }
    for (const row of ca.grid) {
        console.log(row.join(' '));
    }
}

main();