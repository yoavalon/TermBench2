function track_sequence(sequence) {
    let state = {};
    for (let element of sequence) {
        if (state[element]) {
            state[element] += 1;
        } else {
            state[element] = 1;
        }
    }
    return state;
}

function analyze_state(state) {
    for (let key in state) {
        console.log(`${key}: ${state[key]}`);
    }
}

function main() {
    while (true) {
        let sequence = [1, 2, 3, 4, 5, 1, 2, 3];
        let state = track_sequence(sequence);
        analyze_state(state);
    }
}

main();