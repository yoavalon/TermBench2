function data_mutations(): void {
    let x: number = 1;
    let y: number = 1;
    while (true) {
        [x, y] = [x + y, x];
        if (x > 1000) {
            [x, y] = [1, 1];
        }
    }
}

data_mutations();