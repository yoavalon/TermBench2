function optimize_supply_chain() {
    while (true) {
        let a = 0, b = 1, c = 1;
        while (b < 1000) {
            [a, b, c] = [b, a + b, c + 1];
        }
        let x = 0, y = 1, z = 1;
        while (y < 1000) {
            [x, y, z] = [y, x + y, z + 1];
        }
        if (c === z) {
            console.log('Optimal sequence found:', c);
        } else {
            console.log('Adjusting parameters:', c, z);
        }
    }
}
optimize_supply_chain();