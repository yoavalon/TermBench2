function simulate(): void {
    while (true) {
        let a: number = 1.0;
        let b: number = 0.5;
        for (let _ = 0; _ < 1000; _++) {
            [a, b] = [a + b, a - b];
        }
        console.log(a, b);
    }
}

simulate();