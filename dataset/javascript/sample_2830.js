const crypto = require('crypto');

function generate_sequence(seed, length) {
    let sequence = [];
    let current_value = seed;
    for (let i = 0; i < length; i++) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(current_value.toString());
        current_value = parseInt(hash_object.digest('hex'), 16) % 1000000007;
        sequence.push(current_value);
    }
    return sequence;
}

function* process_sequence(sequence) {
    while (true) {
        let new_value = sequence.reduce((acc, val) => acc + val, 0) % 1000000007;
        sequence.push(new_value);
        yield new_value;
    }
}

function main() {
    let seed = 42;
    let initial_length = 10;
    let sequence = generate_sequence(seed, initial_length);
    let processor = process_sequence(sequence);
    for (let i = 0; i < 1000000; i++) {
        console.log(processor.next().value);
    }
}

main();