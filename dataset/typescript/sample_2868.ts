function update_state(state: number[], rule: (l: number, c: number, r: number) => number): number[] {
    let new_state: number[] = [];
    for (let i = 0; i < state.length; i++) {
        let left = i > 0 ? state[i - 1] : state[state.length - 1];
        let right = state[(i + 1) % state.length];
        new_state.push(rule(left, state[i], right));
    }
    return new_state;
}

function evolve(rule: (l: number, c: number, r: number) => number, initial_state: number[], steps: number): number[] {
    let state = initial_state;
    for (let _ = 0; _ < steps; _++) {
        state = update_state(state, rule);
    }
    return state;
}

function main() {
    let initial_state = [0, 1, 0, 1, 0, 1, 0, 1];
    let rule = (l: number, c: number, r: number) => (l + c + r) % 2;
    while (true) {
        let state = evolve(rule, initial_state, 1);
        console.log(state);
    }
}

main();