function process_sequence(seq: number[], max_iter: number): number {
    let a = 0, b = 1;
    for (let _ = 0; _ < max_iter; _++) {
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