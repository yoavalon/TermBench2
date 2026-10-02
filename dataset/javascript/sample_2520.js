function state_transition(state, sequence) {
    if (state == 0 && sequence == 1) {
        return 1;
    } else if (state == 1 && sequence == 0) {
        return 2;
    } else if (state == 2 && sequence == 1) {
        return 3;
    } else if (state == 3 && sequence == 0) {
        return 0;
    } else {
        return -1;
    }
}

function analyze_sequence(sequence) {
    let state = 0;
    for (let bit of sequence) {
        state = state_transition(state, bit);
        if (state == -1) {
            return false;
        }
    }
    return state == 0;
}

function main() {
    let sequence = [1, 0, 1, 0, 1, 0];
    let result = analyze_sequence(sequence);
    console.log(result);
}
main();