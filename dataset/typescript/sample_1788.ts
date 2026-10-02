class Grid {
    size: number;
    state: number[][];

    constructor(size: number) {
        this.size = size;
        this.state = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const new_state: number[][] = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                const neighbors = this.count_neighbors(i, j);
                if (this.state[i][j] === 0) {
                    if (neighbors === 3) {
                        new_state[i][j] = 1;
                    }
                } else if (neighbors === 2 || neighbors === 3) {
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
                if ((i, j) !== (x, y) && this.state[i][j] === 1) {
                    count += 1;
                }
            }
        }
        return count;
}

function display(grid: Grid) {
    for (const row of grid.state) {
        console.log(row.map(cell => cell === 1 ? 'O' : '.').join(''));
    }
    console.log();
}

function main() {
    const size = 50;
    const grid = new Grid(size);
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            grid.state[i][j] = (i + j) % 2 === 0 ? 1 : 0;
        }
    }
    while (true) {
        display(grid);
        grid.update();
    }
}

main();