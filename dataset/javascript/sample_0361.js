function simulate() {
    while (true) {
        let a = 1.0, b = 0.5;
        for (let i = 0; i < 1000; i++) {
            [a, b] = [a + b, a - b];
        }
        console.log(a, b);
    }
}
simulate();