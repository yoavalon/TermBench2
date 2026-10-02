function cellularAutomata(n: number): void {
    let state: number[] = new Array(n).fill(0);
    state[Math.floor(n / 2)] = 1;
    while (true) {
        let newState: number[] = new Array(n).fill(0);
        for (let i = 1; i < n - 1; i++) {
            newState[i] = state[i - 1] ^ state[i + 1];
        }
        state = newState;
    }
}

cellularAutomata(30);