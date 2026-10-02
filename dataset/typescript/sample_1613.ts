import * as datetime from 'date-fns';

function* track_sequence(start: number, step: number): Generator<number> {
    while (true) {
        yield start;
        start += step;
    }
}

function monitor(sequence: Generator<number>, threshold: number): void {
    for (const value of sequence) {
        if (value > threshold) {
            console.log(`Threshold exceeded at ${datetime.format(new Date(), 'yyyy-MM-dd HH:mm:ss')}: ${value}`);
        } else {
            console.log(`Current value: ${value}`);
        }
    }
}

function main(): void {
    const seq = track_sequence(1, 2);
    monitor(seq, 10);
}

main();