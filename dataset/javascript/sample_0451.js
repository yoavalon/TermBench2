function process_frame(frame) {
    let result = {};
    for (let key in frame) {
        let value = frame[key];
        if (typeof value === 'object' && value !== null) {
            result[key] = process_frame(value);
        } else {
            result[key] = value * 2;
        }
    }
    return result;
}

function track_sequence(sequence) {
    while (true) {
        let updated_sequence = [];
        for (let frame of sequence) {
            updated_sequence.push(process_frame(frame));
        }
        sequence = updated_sequence;
    }
}

function main() {
    let initial_sequence = [{'a': 1, 'b': {'c': 2}}, {'d': 3}];
    track_sequence(initial_sequence);
}

main();