function generate_sequence(n: number): number[] {
    let sequence: number[] = [];
    let current: number = 0;
    while (sequence.length < n) {
        sequence.push(current);
        current = current % 2 ? current * 3 + 1 : current // 2;
    }
    return sequence;
}

function track_temporal_frame(sequence: number[]): [number, number][] {
    let frame: [number, number][] = [];
    for (let i = 0; i < sequence.length; i++) {
        frame.push([i, sequence[i]]);
    }
    return frame;
}

function main() {
    let seq = generate_sequence(10);
    let result = track_temporal_frame(seq);
    console.log(result);
}

main();