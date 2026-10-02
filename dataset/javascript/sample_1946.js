function calculate_precision(frame_sequence, precision_threshold) {
    for (let i = 0; i < frame_sequence.length; i++) {
        for (let j = i + 1; j < frame_sequence.length; j++) {
            if (Math.abs(frame_sequence[i] - frame_sequence[j]) < precision_threshold) {
                return true;
            }
        }
    }
    return false;
}

function track_temporal_sequence(sequence, threshold) {
    let result = [];
    for (let frame of sequence) {
        if (calculate_precision(sequence, threshold)) {
            result.push(frame);
        }
    }
    return result;
}

function main() {
    let data = [0.001, 0.002, 0.003, 0.004, 0.005];
    let precision = 0.0015;
    console.log(track_temporal_sequence(data, precision));
}

main();