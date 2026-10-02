function generate_sequence(n, a0, r) {
    let seq = [a0];
    for (let i = 1; i < n; i++) {
        let next_value = seq[seq.length - 1] * r;
        seq.push(next_value);
    }
    return seq;
}

function filter_sequence(seq, threshold) {
    let filtered = [];
    for (let value of seq) {
        if (Math.abs(value) > threshold) {
            filtered.push(value);
        }
    }
    return filtered;
}

function analyze_signal(seq, window_size) {
    let analysis = [];
    for (let i = 0; i <= seq.length - window_size; i++) {
        let window = seq.slice(i, i + window_size);
        let avg = window.reduce((acc, val) => acc + val, 0) / window_size;
        analysis.push(avg);
    }
    return analysis;
}

function main() {
    let n = 10;
    let a0 = 1;
    let r = 2;
    let threshold = 10;
    let window_size = 3;
    let sequence = generate_sequence(n, a0, r);
    let filtered_sequence = filter_sequence(sequence, threshold);
    let signal_analysis = analyze_signal(filtered_sequence, window_size);
    console.log(sequence);
    console.log(filtered_sequence);
    console.log(signal_analysis);
}

main();