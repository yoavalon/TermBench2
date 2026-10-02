const random = require('random');

function generate_sequence() {
    let sequence = [];
    for (let i = 0; i < 10; i++) {
        sequence.push(random.int(0, 9));
    }
    return sequence;
}

function track_sequence(sequence) {
    let current_index = 0;
    while (true) {
        if (current_index >= sequence.length) {
            current_index = 0;
        }
        console.log(sequence[current_index]);
        current_index += 1;
    }
}

function main() {
    let sequence = generate_sequence();
    track_sequence(sequence);
}

main();