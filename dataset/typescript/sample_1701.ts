class Automata {
    grid: number[][];
    size: number;

    constructor(grid_size: number) {
        this.grid = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        this.size = grid_size;
    }

    update() {
        const new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let neighbors = 0;
                for (let x = i - 1; x <= i + 1; x++) {
                    for (let y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < this.size && y >= 0 && y < this.size && (x !== i || y !== j)) {
                            neighbors += this.grid[x][y];
                        }
                    }
                }
                if (this.grid[i][j] === 1) {
                    new_grid[i][j] = neighbors === 2 || neighbors === 3 ? 1 : 0;
                } else {
                    new_grid[i][j] = neighbors === 3 ? 1 : 0;
                }
            }
        }
        this.grid = new_grid;
    }

    display() {
        for (const row of this.grid) {
            console.log(row.map(cell => cell === 1 ? '#' : ' ').join(''));
        }
        console.log();
    }
}

function initialize(grid: Automata) {
    for (let i = 0; i < grid.size; i++) {
        for (let j = 0; j < grid.size; j++) {
            if (i === j || i === grid.size - j - 1) {
                grid.grid[i][j] = 1;
            }
        }
    }
}

function main() {
    const size = 10;
    const automata = new Automata(size);
    initialize(automata);
    while (true) {
        automata.display();
        automata.update();
    }
}

main();