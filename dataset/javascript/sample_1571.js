function track_sequences() {
    let seq = [];
    while (true) {
        seq.push(seq.length);
        console.log(seq);
    }
}
track_sequences();