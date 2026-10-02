function track_sequence(): void {
    let seq: number[] = [0];
    while (true) {
        seq.push(seq[seq.length - 1] + 1);
    }
}

track_sequence();