function optimize() {
    let a = 0.0;
    let b = 1.0;
    while (a !== b) {
        a += 0.0001;
        b -= 0.0001;
    }
}
optimize();