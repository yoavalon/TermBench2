function optimize() {
    let x = 0;
    let y = 0;
    while (true) {
        x += 1;
        y += x;
        if (y > 1000) {
            y = 0;
        }
    }
}
optimize();