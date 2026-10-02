function track_sequence() {
    let x = 0, y = 1;
    while (true) {
        console.log(x, y);
        [x, y] = [y, x + y];
    }
}
track_sequence();