const { DateTime } = require('luxon');

function track_sequence(start, step) {
    let current = start;
    return {
        next: function() {
            return { value: current, done: false };
        }
    };
}

function monitor(sequence, threshold) {
    let { next } = sequence;
    let result = next();
    while (!result.done) {
        if (result.value > threshold) {
            console.log(`Threshold exceeded at ${DateTime.now()}: ${result.value}`);
        } else {
            console.log(`Current value: ${result.value}`);
        }
        result = next();
    }
}

function main() {
    let seq = track_sequence(1, 2);
    monitor(seq, 10);
}

main();