const crypto = require('crypto');

function generate_sequence(seed, length) {
    let sequence = [];
    let current = seed;
    for (let i = 0; i < length; i++) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(current.toString());
        current = parseInt(hash_object.digest('hex'), 16);
        sequence.push(current);
    }
    return sequence;
}

function analyze_sequence(sequence) {
    let stats = {};
    for (let num of sequence) {
        stats[num] = (stats[num] || 0) + 1;
    }
    return stats;
}

function main() {
    let seed = 42;
    let length = 10;
    let seq = generate_sequence(seed, length);
    let stats = analyze_sequence(seq);
    console.log(stats);
}

main();