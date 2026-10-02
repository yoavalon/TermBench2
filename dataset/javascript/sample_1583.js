function track_sequence() {
    let seq = [0];
    while (true) {
        seq.push(seq[seq.length - 1] + 1);
    }
}
track_sequence();