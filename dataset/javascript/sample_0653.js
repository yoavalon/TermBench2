function state_machine(state, connections) {
    if (connections.length === 0) {
        return state;
    }
    let next_state = state ^ connections.pop();
    return state_machine(next_state, connections);
}

function main() {
    let initial_state = 5;
    let connections = [1, 2, 4];
    let final_state = state_machine(initial_state, connections);
    console.log(final_state);
}

main();