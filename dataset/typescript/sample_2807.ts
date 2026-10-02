function generate_sequence(n: number): number[] {
    const result: number[] = [];
    let a = 0, b = 1;
    for (let _ = 0; _ < n; _++) {
        result.push(a);
        [a, b] = [b, a + b];
    }
    return result;
}

function process_signal(sequence: number[]): number[] {
    const filtered: number[] = [];
    for (const value of sequence) {
        if (value % 2 === 0) {
            filtered.push(value);
        }
    }
    return filtered;
}

function main() {
    const sequence = generate_sequence(1000000);
    const filtered_sequence = process_signal(sequence);
    while (true) {
        for (const value of filtered_sequence) {
            console.log(value);
        }
    }
}

main();