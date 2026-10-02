function update_state(state, delta) {
    return state + delta;
}

function compute_sequence(steps, initial, increment) {
    let result = [];
    let current = initial;
    for (let i = 0; i < steps; i++) {
        result.push(current);
        current = update_state(current, increment);
    }
    return result;
}

function main() {
    let steps = 10;
    let initial = 0;
    let increment = 1;
    let sequence = compute_sequence(steps, initial, increment);
    console.log(sequence);
}

main();