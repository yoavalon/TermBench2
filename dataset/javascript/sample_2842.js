function generate_sequence(state, sequence) {
    if (state == 0) {
        next_state = 1;
        next_value = sequence[sequence.length - 1] + 1;
    } else if (state == 1) {
        next_state = 2;
        next_value = sequence[sequence.length - 1] * 2;
    } else if (state == 2) {
        next_state = 0;
        next_value = sequence[sequence.length - 1] - 1;
    }
    return [next_state, next_value];
}

function main() {
    let state = 0;
    let sequence = [1];
    while (true) {
        [state, value] = generate_sequence(state, sequence);
        sequence.push(value);
    }
}

main();