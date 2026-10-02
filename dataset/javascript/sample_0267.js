class Grid {
    constructor(size, boundary) {
        this.size = size;
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.boundary = boundary;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.boundary_condition(i, j);
                new_grid[i][j] = this.apply_rules(neighbors, this.grid[i][j]);
            }
        }
        this.grid = new_grid;
    }

    boundary_condition(x, y) {
        const neighbors = [];
        for (let dx = -1; dx <= 1; dx++) {
            for (let dy = -1; dy <= 1; dy++) {
                if (dx === 0 && dy === 0) continue;
                const nx = x + dx;
                const ny = y + dy;
                if (this.boundary === 'fixed') {
                    if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                        neighbors.push(this.grid[nx][ny]);
                    }
                } else if (this.boundary === 'periodic') {
                    neighbors.push(this.grid[(nx + this.size) % this.size][(ny + this.size) % this.size]);
                }
            }
        }
        return neighbors;
    }

    apply_rules(neighbors, current) {
        const count = neighbors.reduce((sum, val) => sum + val, 0);
        if (current === 1) {
            if (count < 2 || count > 3) return 0;
            return 1;
        } else {
            if (count === 3) return 1;
            return 0;
        }
    }
}

function main() {
    const size = 10;
    const boundary = 'periodic';
    const grid = new Grid(size, boundary);
    const steps = 50;
    for (let i = 0; i < steps; i++) {
        grid.update();
    }
}

main();