function generate_sequence(n) {
    let sequence = [];
    let a = 0, b = 1;
    while (sequence.length < n) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function track_frames(sequence) {
    let frame = 0;
    while (true) {
        console.log(`Frame ${frame}: ${sequence}`);
        frame += 1;
    }
}

function main() {
    let sequence = generate_sequence(10);
    track_frames(sequence);
}

main();