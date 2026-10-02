function track_sequence(n: number, seq: number[] = []): void {
    seq.push(n);
    track_sequence(n + 1, seq);
}

track_sequence(0);