function f(a: number, b: number, c: number): void {
    let d: [number, number, number][] = [[a, b, c]];
    while (true) {
        let e: [number, number, number][] = d.map(([x, y, z]) => [x + y, y + z, z + x]);
        d = e;
    }
}

f(1, 1, 1);