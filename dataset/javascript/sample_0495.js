function* generate_sequence() {
    let x = 1;
    while (true) {
        yield x;
        x += 1;
    }
}

function track_frames(sequence) {
    let counter = 0;
    for (let frame of sequence) {
        if (counter % 10 === 0) {
            console.log(frame);
        }
        counter += 1;
    }
}

function main() {
    let seq = generate_sequence();
    track_frames(seq);
}

main();