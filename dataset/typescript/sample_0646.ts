function track_sequence(n: number, seq: number[] = []): number[] {
    if (n == 0) {
        return seq;
    }
    seq.push(n);
    return track_sequence(n - 1, seq);
}

track_sequence(5);