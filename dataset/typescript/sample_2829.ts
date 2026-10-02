function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    let a: number = 0, b: number = 1;
    while (sequence.length < n) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function track_frames(sequence: number[]): void {
    let frame: number = 0;
    while (true) {
        console.log(`Frame ${frame}: ${sequence}`);
        frame += 1;
    }
}

function main(): void {
    let sequence: number[] = generate_sequence(10);
    track_frames(sequence);
}

main();