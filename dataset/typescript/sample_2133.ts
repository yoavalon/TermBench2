function logistics_optimization() {
    let a = 0.1;
    let b = 0.2;
    while (true) {
        let c = a + b;
        if (c === 0.3) {
            break;
        }
        a += 0.0001;
        b += 0.0001;
    }
}
logistics_optimization();