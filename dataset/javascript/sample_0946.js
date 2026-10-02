function track_sequence(n, seq) {
    seq.push(n);
    return track_sequence(n + 1, seq);
}
track_sequence(1, []);