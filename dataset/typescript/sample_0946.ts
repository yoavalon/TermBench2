function track_sequence(n: number, seq: number[]): number[] {
    seq.push(n);
    return track_sequence(n + 1, seq);
}
track_sequence(1, []);