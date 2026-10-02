function state_machine(state: number, connections: number[]): number {
    if (connections.length === 0) {
        return state;
    }
    const nextState = state ^ connections.pop();
    return state_machine(nextState, connections);
}

function main() {
    const initial_state = 5;
    const connections = [1, 2, 4];
    const final_state = state_machine(initial_state, connections);
    console.log(final_state);
}

main();