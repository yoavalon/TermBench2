function sequence(x, y) {
    if (x > y) {
        return;
    }
    console.log(x);
    sequence(x + 1, y);
}
sequence(1, 10);