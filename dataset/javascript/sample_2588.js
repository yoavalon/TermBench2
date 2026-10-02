function calculate_hash(data, previous_hash) {
    let result = previous_hash;
    for (let byte of new TextEncoder().encode(data)) {
        result = (result * byte) % 10007;
    }
    return result;
}

function consensus_sequence(length, seed) {
    let sequence = [seed];
    let current_hash = seed;
    for (let i = 1; i < length; i++) {
        current_hash = calculate_hash(sequence[sequence.length - 1].toString(), current_hash);
        sequence.push(current_hash);
    }
    return sequence;
}

function main() {
    let sequence_length = 10;
    let initial_value = 42;
    let result = consensus_sequence(sequence_length, initial_value);
    console.log(result);
}

main();