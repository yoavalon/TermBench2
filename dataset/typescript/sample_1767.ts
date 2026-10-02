class Grid {
    size: number;
    state: number[][];

    constructor(size: number, initial_state: number[][]) {
        this.size = size;
        this.state = initial_state;
    }

    update() {
        const new_state: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.state[i][j] === 1 && (neighbors === 2 || neighbors === 3)) {
                    new_state[i][j] = 1;
                } else if (this.state[i][j] === 0 && neighbors === 3) {
                    new_state[i][j] = 1;
                }
            }
        }
        this.state = new_state;
    }

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(this.size, x + 2); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(this.size, y + 2); j++) {
                if ((i !== x || j !== y) && this.state[i][j] === 1) {
                    count += 1;
                }
            }
        }
        return count;
}

function generate_initial_state(size: number, density: number): number[][] {
    return Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.random() < density ? 1 : 0));
}

function main() {
    const size = 100;
    const density = 0.2;
    const grid = new Grid(size, generate_initial_state(size, density));
    while (true) {
        grid.update();
    }
}

main();