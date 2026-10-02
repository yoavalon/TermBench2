function simulate(): void {
    let a = 10, b = 20, c = 30, d = 40;
    for (let _ = 0; _ < 5; _++) {
        [a, b, c, d] = [b, c, d, a + b + c + d];
    }
    console.log(a, b, c, d);
}

simulate();