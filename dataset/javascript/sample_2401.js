function process_sequence(seq) {
    const states = {'open': 0, 'closed': 1};
    const transitions = [[0, 1], [1, 0]];
    let current = states['open'];
    const result = [];
    for (let _ = 0; _ < seq.length; _++) {
        current = transitions[current][seq[_] % 2 === 0 ? 0 : 1];
        result.push(current);
    }
    return result;
}

function main() {
    const seq = [0, 1, 2, 3, 4, 5];
    console.log(process_sequence(seq));
}

main();