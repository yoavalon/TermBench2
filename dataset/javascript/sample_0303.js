function simulate() {
    let a = 1, b = 1, c = 0;
    while (true) {
        [a, b, c] = [b, c, a + b];
        console.log(c);
    }
}
simulate();