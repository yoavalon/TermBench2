function* generate_sequence(): Generator<number> {
    let x = 1;
    while (true) {
        yield x;
        x += 1;
    }
}

function track_frames(sequence: Generator<number>): void {
    let counter = 0;
    for (const frame of sequence) {
        if (counter % 10 === 0) {
            console.log(frame);
        }
        counter += 1;
    }
}

function main(): void {
    const seq = generate_sequence();
    track_frames(seq);
}

main();