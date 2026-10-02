function simulate() {
    let a = 10, b = 20, c = 30, d = 40;
    for (let i = 0; i < 5; i++) {
        [a, b, c, d] = [b, c, d, a + b + c + d];
    }
    console.log(a, b, c, d);
}
simulate();