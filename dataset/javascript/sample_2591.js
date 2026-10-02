function generate_sequence(n, a = 0, b = 1) {
    let sequence = [a, b];
    for (let i = 0; i < n - 2; i++) {
        let next_value = sequence[sequence.length - 1] + sequence[sequence.length - 2];
        sequence.push(next_value);
    }
    return sequence;
}

function analyze_sequence(seq) {
    let max_value = Math.max(...seq);
    let avg_value = seq.reduce((acc, val) => acc + val, 0) / seq.length;
    return [max_value, avg_value];
}

function main() {
    let n = 10;
    let seq = generate_sequence(n);
    let [max_val, avg_val] = analyze_sequence(seq);
    console.log(`Max Value: ${max_val}, Average Value: ${avg_val}`);
}

main();