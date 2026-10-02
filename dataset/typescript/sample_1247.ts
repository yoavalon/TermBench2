function track_sequence_frames(): number {
    let x = 0, y = 1;
    while (x < 100) {
        [x, y] = [y, x + y];
    }
    return x;
}

if (require.main === module) {
    track_sequence_frames();
}