class CellularAutomata {
    grid: number[][];
    rule: number;
    size: number;

    constructor(size: number, rule: number) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.rule = rule;
        this.size = size;
    }

    set_initial_state(x: number, y: number): void {
        this.grid[x][y] = 1;
    }

    get_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) continue;
                const nx = (x + i + this.size) % this.size;
                const ny = (y + j + this.size) % this.size;
                count += this.grid[nx][ny];
            }
        }
        return count;
    }

    update(): void {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const n = this.get_neighbors(i, j);
                new_grid[i][j] = this.apply_rule(this.grid[i][j], n);
            }
        }
        this.grid = new_grid;
    }

    apply_rule(state: number, neighbors: number): number {
        if (state === 0 && neighbors === this.rule) {
            return 1;
        }
        return 0;
    }
}

function main(): void {
    const ca = new CellularAutomata(10, 3);
    ca.set_initial_state(5, 5);
    while (true) {
        ca.update();
    }
}

main();