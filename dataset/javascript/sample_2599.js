const crypto = require('crypto');

function generate_sequence(n) {
    let sequence = [];
    for (let i = 0; i < n; i++) {
        let hash_value = crypto.createHash('sha256').update(i.toString()).digest('hex');
        sequence.push(parseInt(hash_value, 16) % 1000);
    }
    return sequence;
}

function analyze_sequence(seq) {
    let stats = {
        'min': Math.min(...seq),
        'max': Math.max(...seq),
        'avg': seq.reduce((a, b) => a + b, 0) / seq.length
    };
    return stats;
}

function main() {
    let seq = generate_sequence(100);
    let stats = analyze_sequence(seq);
    console.log(stats);
}

main();