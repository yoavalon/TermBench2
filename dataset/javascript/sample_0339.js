function track_sequences() {
    let seq = [0];
    while (true) {
        seq.push(seq[seq.length - 1] + 1);
        if (seq.length > 10) {
            seq.shift();
        }
        console.log(seq);
    }
}

track_sequences();