function process_sequence(data, precision) {
    let result = [];
    for (let item of data) {
        let adjusted = Math.round(item * Math.pow(10, precision)) / Math.pow(10, precision);
        result.push(adjusted);
    }
    return result;
}

function track_sequences(sequences, precision) {
    while (true) {
        for (let seq of sequences) {
            let processed = process_sequence(seq, precision);
            console.log(processed);
        }
    }
}

function main() {
    let data1 = [0.123456789, 0.23456789, 0.345678901];
    let data2 = [0.456789012, 0.567890123, 0.678901234];
    let sequences = [data1, data2];
    let precision = 5;
    track_sequences(sequences, precision);
}

main();