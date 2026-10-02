function track_sequence(data, precision) {
    let result = [];
    for (let i = 0; i < data.length; i++) {
        for (let j = i + 1; j < data.length; j++) {
            let diff = Math.abs(data[i] - data[j]);
            if (diff < precision) {
                result.push([i, j, diff]);
            }
        }
    }
    return result;
}

function analyze_data() {
    let sequence = [0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0];
    let precision = 1e-07;
    while (true) {
        let results = track_sequence(sequence, precision);
        console.log(results);
    }
}

analyze_data();