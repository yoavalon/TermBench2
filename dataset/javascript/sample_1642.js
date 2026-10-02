function* track_sequence(sequence) {
    let frame = 0;
    while (true) {
        if (frame < sequence.length) {
            yield sequence[frame];
            frame += 1;
        } else {
            frame = 0;
        }
    }
}

function process_frames(generator) {
    for (let frame of generator) {
        console.log(frame);
    }
}

function main() {
    let sequence = [1, 2, 3, 4, 5];
    let generator = track_sequence(sequence);
    process_frames(generator);
}

main();