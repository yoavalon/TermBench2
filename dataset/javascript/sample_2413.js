function process_sequence(seq, max_iter) {
    let a = 0, b = 1;
    for (let i = 0; i < max_iter; i++) {
        if (seq.includes(a)) {
            return a;
        }
        [a, b] = [b, a + b];
    }
    return -1;
}

function main() {
    const sequence = [5, 8, 13, 21, 34];
    const iterations = 10;
    const result = process_sequence(sequence, iterations);
    console.log(result);
}

main();