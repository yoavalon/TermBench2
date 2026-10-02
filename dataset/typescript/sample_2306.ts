class Automaton {
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
                if (this.state[i][j] === 1) {
                    new_state[i][j] = (2 <= neighbors && neighbors <= 3) ? 1 : 0;
                } else {
                    new_state[i][j] = (neighbors === 3) ? 1 : 0;
                }
            }
        }
        this.state = new_state;
    }

    count_neighbors(x: number, y: number): number {
        let count = 0;
        for (let i = x - 1; i < x + 2; i++) {
            for (let j = y - 1; j < y + 2; j++) {
                if (0 <= i && i < this.size && 0 <= j && j < this.size && (i !== x || j !== y)) {
                    count += this.state[i][j];
                }
            }
        }
        return count;
}

function generate_initial_state(size: number): number[][] {
    const random = require('random');
    return Array.from({ length: size }, () => Array(size).fill(0).map(() => random.int(0, 1)));
}

function main() {
    const size = 10;
    const initial_state = generate_initial_state(size);
    const automaton = new Automaton(size, initial_state);
    while (true) {
        automaton.update();
    }
}

main();