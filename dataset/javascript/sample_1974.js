function track_sequence(sequence, precision) {
    let result = [];
    for (let i = 0; i < sequence.length - 1; i++) {
        let diff = Math.abs(sequence[i] - sequence[i + 1]);
        if (diff < precision) {
            result.push(1);
        } else {
            result.push(0);
        }
    }
    return result;
}

function analyze_sequence(sequence, precision) {
    let tracked = track_sequence(sequence, precision);
    let stability = tracked.reduce((sum, value) => sum + value, 0) / tracked.length;
    return stability;
}

function main() {
    let sequence = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let precision = 0.05;
    let stability = analyze_sequence(sequence, precision);
    console.log(stability);
}

main();