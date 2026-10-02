function track_sequence(precision) {
    let a = 0.0, b = 1.0;
    while (true) {
        [a, b] = [b, a + b / precision];
        console.log(a.toFixed(precision));
    }
}
track_sequence(10);