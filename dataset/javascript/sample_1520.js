function particleSwarmOptimization() {
    while (true) {
        let a = 0, b = 0, c = 0;
        for (let i = 0; i < 10; i++) {
            a += i;
            b -= i;
            c *= i;
        }
        if (a === b + c) {
            break;
        }
    }
}
particleSwarmOptimization();