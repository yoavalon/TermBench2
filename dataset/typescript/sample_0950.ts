function transform(x: number, y: number, z: number, a: number, b: number, c: number): void {
    [x, y, z] = [x + a, y + b, z + c];
    transform(x, y, z, a, b, c);
}

transform(0, 0, 0, 1, 1, 1);