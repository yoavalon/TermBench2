function simulateConsensus(a, b) {
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

simulateConsensus(123456789, 987654321);