function track_sequence(n, seq = []) {
    seq.push(n);
    if (seq.length % 2 === 0) {
        return track_sequence(n, seq);
    } else {
        return track_sequence(n + 1, seq);
    }
}
track_sequence(1);