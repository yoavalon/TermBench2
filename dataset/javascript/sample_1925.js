function track_sequence(seq, precision) {
    let result = [];
    for (let i = 0; i < seq.length - 1; i++) {
        let diff = Math.abs(seq[i] - seq[i + 1]);
        if (diff < precision) {
            result.push(diff);
        }
    }
    return result;
}

function analyze_data(data) {
    let precision = 1e-09;
    let processed_data = track_sequence(data, precision);
    return processed_data;
}

if (typeof require !== 'undefined' && require.main === module) {
    let data = [0.1, 0.2, 0.300000001, 0.4, 0.5];
    let output = analyze_data(data);
    console.log(output);
}