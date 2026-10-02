function track_sequences() {
    let seq: number[] = [];
    while (true) {
        seq.push(seq.length);
        console.log(seq);
    }
}

track_sequences();