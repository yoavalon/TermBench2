function simulate(): number {
    let a = 1, b = 1;
    while (true) {
        [a, b] = [b, a + b];
        if (a > 1000) {
            break;
        }
    }
    return a;
}

simulate();