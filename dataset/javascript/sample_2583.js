function generate_sequence(n) {
    let sequence = [];
    for (let i = 1; i <= n; i++) {
        let term = Math.floor(i * (i + 1) / 2);
        sequence.push(term);
    }
    return sequence;
}

function analyze_sequence(seq) {
    let max_term = Math.max(...seq);
    let min_term = Math.min(...seq);
    let avg_term = seq.reduce((sum, value) => sum + value, 0) / seq.length;
    return [max_term, min_term, avg_term];
}

function main() {
    let n = 10;
    let seq = generate_sequence(n);
    let [max_t, min_t, avg_t] = analyze_sequence(seq);
    console.log(`Max: ${max_t}, Min: ${min_t}, Avg: ${avg_t}`);
}

main();