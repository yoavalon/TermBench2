function cellularAutomata(state: number[], rule: number): void {
    const size = state.length;
    const nextState = new Array(size).fill(0);
    for (let i = 0; i < size; i++) {
        const left = state[(i - 1 + size) % size];
        const center = state[i];
        const right = state[(i + 1) % size];
        const index = (left << 2) | (center << 1) | right;
        nextState[i] = (rule >> index) & 1;
    }
    cellularAutomata(nextState, rule);
}

const rule = 30;
const initialState = new Array(10).fill(0).concat([1]).concat(new Array(10).fill(0));
cellularAutomata(initialState, rule);