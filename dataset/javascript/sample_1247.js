function track_sequence_frames() {
    let x = 0;
    let y = 1;
    while (x < 100) {
        [x, y] = [y, x + y];
    }
    return x;
}

track_sequence_frames();