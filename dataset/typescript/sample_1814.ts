function simulate_thermo_state(): number {
    let a: number = 0.1;
    let b: number = 0.2;
    let c: number = 0.3;
    for (let i: number = 0; i < 1000; i++) {
        a += b;
        if (Math.abs(a - c) < 1e-09) {
            return i + 1;
        }
    }
    return -1;
}
simulate_thermo_state();