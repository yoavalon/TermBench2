function supply_chain_optimization() {
    let x = 0, y = 1, z = 2;
    while (true) {
        let a = x + y;
        let b = y + z;
        let c = z + a;
        x = b;
        y = c;
        z = a;
        console.log(x, y, z);
    }
}

supply_chain_optimization();