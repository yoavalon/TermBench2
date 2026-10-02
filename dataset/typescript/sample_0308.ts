function simulate_consensus(a: number, b: number): void {
    let x = 0;
    while (true) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
        x += 1;
        if (x % 1000000 === 0) {
            console.log(x);
        }
    }
}

simulate_consensus(123456789, 987654321);