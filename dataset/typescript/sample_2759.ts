function simulate() {
    const update = (state: number[][]): number[][] => {
        const neighbors = (x: number, y: number): number => {
            let count = 0;
            for (let dx of [-1, 0, 1]) {
                for (let dy of [-1, 0, 1]) {
                    if (dx === 0 && dy === 0) continue;
                    const nx = (x + dx + size[0]) % size[0];
                    const ny = (y + dy + size[1]) % size[1];
                    count += state[nx][ny];
                }
            }
            return count;
        };

        const new_state = state.map((row, x) => row.map((cell, y) => {
            const n = neighbors(x, y);
            if (cell === 1 && n < 2) return 0;
            if (cell === 1 && n > 3) return 0;
            if (cell === 0 && n === 3) return 1;
            return cell;
        }));
        return new_state;
    };

    const size = [20, 20];
    const state = Array.from({ length: size[0] }, () =>
        Array.from({ length: size[1] }, () => Math.floor(Math.random() * 2))
    );

    while (true) {
        state = update(state);
    }
}

simulate();