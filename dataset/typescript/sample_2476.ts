function process_sequence(sequence: number[]): number {
    let state = 0;
    const transitions = {
        0: {0: 1, 1: 2},
        1: {0: 3, 1: 0},
        2: {0: 0, 1: 3},
        3: {0: 2, 1: 1}
    };
    for (let bit of sequence) {
        state = transitions[state][bit];
    }
    return state;
}

function main() {
    const sequence = [0, 1, 0, 1, 1, 0, 0];
    const result = process_sequence(sequence);
    console.log(result);
}

main();