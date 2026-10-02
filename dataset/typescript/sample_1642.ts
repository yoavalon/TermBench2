function* track_sequence(sequence: number[]): Generator<number> {
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

function process_frames(generator: Generator<number>): void {
    for (const frame of generator) {
        console.log(frame);
    }
}

function main(): void {
    const sequence = [1, 2, 3, 4, 5];
    const generator = track_sequence(sequence);
    process_frames(generator);
}

main();