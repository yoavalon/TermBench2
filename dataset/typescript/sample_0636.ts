function track_frames(n: number, seq: number[] = []): number[] {
    if (n === 0) {
        return seq;
    }
    seq.push(n);
    return track_frames(n - 1, seq);
}
track_frames(5);