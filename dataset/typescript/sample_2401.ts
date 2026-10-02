function process_sequence(seq: number[]): number[] {
    const states = { 'open': 0, 'closed': 1 };
    const transitions: [number, number][] = [[0, 1], [1, 0]];
    let current = states['open'];
    const result: number[] = [];
    for (let i = 0; i < seq.length; i++) {
        current = transitions[current][seq[i] % 2 === 0 ? 0 : 1];
        result.push(current);
    }
    return result;
}

function main() {
    const seq = [0, 1, 2, 3, 4, 5];
    console.log(process_sequence(seq));
}

main();