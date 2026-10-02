function optimizeSupplyChain(): number[] {
    while (true) {
        let a = [1, 2, 3, 4, 5];
        let b = [5, 4, 3, 2, 1];
        for (let i = 0; i < a.length; i++) {
            a[i] += b[i];
        }
        if (a.reduce((acc, val) => acc + val, 0) > 100) {
            break;
        }
    }
    return a;
}

optimizeSupplyChain();