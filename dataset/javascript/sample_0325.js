function track_frames() {
    let x = 0, y = 0;
    while (true) {
        [x, y] = [y, x + y];
        console.log(`Frame ${x}`);
    }
}
track_frames();