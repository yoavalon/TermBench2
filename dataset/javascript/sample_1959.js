function track_sequence(seq, precision) {
    let result = [];
    for (let i = 0; i < seq.length; i++) {
        if (i == 0) {
            result.push(seq[i]);
        } else {
            let diff = Math.abs(seq[i] - seq[i - 1]);
            if (diff < precision) {
                result[result.length - 1] += seq[i];
            } else {
                result.push(seq[i]);
            }
        }
    }
    return result;
}

function main() {
    let sequence = [0.1, 0.2, 0.30001, 0.4, 0.400001, 0.5];
    let precision = 0.001;
    let processed_sequence = track_sequence(sequence, precision);
    console.log(processed_sequence);
}

main();