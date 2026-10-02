function data_mutations() {
    let x = 1, y = 1;
    while (true) {
        [x, y] = [x + y, x];
        if (x > 1000) {
            [x, y] = [1, 1];
        }
    }
}
data_mutations();