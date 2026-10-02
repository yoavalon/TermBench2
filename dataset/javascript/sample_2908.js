class Automata {
    constructor(size) {
        this.grid = Array.from({ length: size }, () => Array(size).fill(0));
        this.size = size;
    }

    update() {
        let new_grid = Array.from({ length: this.size }, () => Array(this.size).fill(0));
        for (let i = 0; i < this.size; i++) {
            for (let j = 0; j < this.size; j++) {
                let neighbors = this.count_neighbors(i, j);
                if (this.grid[i][j] === 0 && neighbors === 3) {
                    new_grid[i][j] = 1;
                } else if (this.grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = this.grid[i][j];
                }
            }
        }
        this.grid = new_grid;
    }

    count_neighbors(x, y) {
        let count = 0;
        for (let i = -1; i < 2; i++) {
            for (let j = -1; j < 2; j++) {
                if (i === 0 && j === 0) {
                    continue;
                }
                let nx = x + i;
                let ny = y + j;
                if (nx >= 0 && nx < this.size && ny >= 0 && ny < this.size) {
                    count += this.grid[nx][ny];
                }
            }
        }
        return count;
    }

    display() {
        for (let row of this.grid) {
            console.log(row.map(cell => cell ? '#' : ' ').join(''));
        }
    }
}

function main() {
    let size = 20;
    let automata = new Automata(size);
    while (true) {
        automata.display();
        automata.update();
    }
}

main();