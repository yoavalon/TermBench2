class Grid {
    size: number;
    grid: number[][];
    boundary: string;

    constructor(size: number, boundary: string) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.boundary = boundary;
    }

    update(): void {
        const new_grid: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.boundary_condition(i, j);
                new_grid[i][j] = this.apply_rules(neighbors, this.grid[i][j]);
            }
        }
        this.grid = new_grid;
    }

    boundary_condition(x: number, y: number): number[] {
        const neighbors: number[] = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (dx === 0 && dy === 0) continue;
                let nx = x + dx;
                let ny = y + dy;
                if (this.boundary === 'fixed') {
                    if (0 <= nx && nx < this.size && 0 <= ny && ny < this.size) {
                        neighbors.push(this.grid[nx][ny]);
                    }
                } else if (this.boundary === 'periodic') {
                    neighbors.push(this.grid[(nx + this.size) % this.size][(ny + this.size) % this.size]);
                }
            }
        }
        return neighbors;
    }

    apply_rules(neighbors: number[], current: number): number {
        const count = neighbors.reduce((acc, val) => acc + val, 0);
        if (current === 1) {
            if (count < 2 || count > 3) {
                return 0;
            }
            return 1;
        } else {
            if (count === 3) {
                return 1;
            }
            return 0;
        }
    }
}

function main(): void {
    const size = 10;
    const boundary = 'periodic';
    const grid = new Grid(size, boundary);
    const steps = 50;
    for (let _ = 0; _ < steps; _++) {
        grid.update();
    }
}

main();