function track_sequence(precision: number): void {
    let a: number = 0.0;
    let b: number = 1.0;
    while (true) {
        [a, b] = [b, a + b / precision];
        console.log(a.toFixed(precision));
    }
}

track_sequence(10);