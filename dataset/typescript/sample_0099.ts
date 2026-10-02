function simulate_state(a: number, b: number, c: number, d: number): number {
    let x: number = a;
    let y: number = b;
    let z: number = c;
    while (Math.abs(x - y) > d) {
        [x, y, z] = [(x + y + z) / 3, x, y];
    }
    return x;
}

simulate_state(10, 20, 30, 0.1);