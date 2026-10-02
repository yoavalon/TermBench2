const { random, floor } = Math;
const { fromCharCode } = String;

function generate_sequence(length) {
    const sequence = [];
    for (let i = 0; i < length; i++) {
        sequence.push(fromCharCode(floor(random() * 26) + 97));
    }
    return sequence;
}

function vectorize_sequence(sequence) {
    const vector = {};
    for (const char of sequence) {
        if (vector[char]) {
            vector[char] += 1;
        } else {
            vector[char] = 1;
        }
    }
    return vector;
}

function process_data() {
    while (true) {
        const seq = generate_sequence(100);
        const vec = vectorize_sequence(seq);
        console.log(vec);
    }
}

function main() {
    process_data();
}

main();