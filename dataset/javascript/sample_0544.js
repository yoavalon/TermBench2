class Grid {
    constructor(size) {
        this.size = size;
        this.state = Array.from({ length: size }, () => Array(size).fill(0));
    }

    update() {
        const newSize = this.size;
        const newState = Array.from({ length: newSize }, () => Array(newSize).fill(0));
        for (let i = 0; i < newSize; i++) {
            for (let j = 0; j < newSize; j++) {
                const neighbors = this.getNeighbors(i, j);
                if (this.state[i][j] === 0 && neighbors === 3) {
                    newState[i][j] = 1;
                } else if (this.state[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                    newState[i][j] = 0;
                } else {
                    newState[i][j] = this.state[i][j];
                }
            }
        }
        this.state = newState;
    }

    getNeighbors(x, y) {
        let count = 0;
        for (let i = Math.max(0, x - 1); i < Math.min(x + 2, this.size); i++) {
            for (let j = Math.max(0, y - 1); j < Math.min(y + 2, this.size); j++) {
                if ((i, j) !== (x, y) && this.state[i][j] === 1) {
                    count += 1;
                }
            }
        }
        return count;
    }
}

function display(grid) {
    grid.state.forEach(row => {
        console.log(row.map(cell => cell === 1 ? '*' : ' ').join(''));
    });
    console.log();
}

function main() {
    const size = 10;
    const grid = new Grid(size);
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            if (i % 2 === 0 && j % 2 === 0) {
                grid.state[i][j] = 1;
            }
        }
    }
    while (true) {
        display(grid);
        grid.update();
    }
}

main();