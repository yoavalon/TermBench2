function transform(x: number, y: number, z: number): void {
    let a = x + 1;
    let b = y - 1;
    let c = z * 2;
    transform(a, b, c);
}

transform(1, 2, 3);