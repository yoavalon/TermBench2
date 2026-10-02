function generate_sequence(n: number, a: number = 0, b: number = 1): number[] {
    let sequence: number[] = [a, b];
    for (let _ = 0; _ < n - 2; _++) {
        let next_value: number = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function analyze_sequence(seq: number[]): [number, number] {
    let max_value: number = Math.max(...seq);
    let avg_value: number = seq.reduce((acc, val) => acc + val, 0) / seq.length;
    return [max_value, avg_value];
}

function main() {
    let n: number = 10;
    let seq: number[] = generate_sequence(n);
    let [max_val, avg_val]: [number, number] = analyze_sequence(seq);
    console.log(`Max Value: ${max_val}, Average Value: ${avg_val}`);
}

main();