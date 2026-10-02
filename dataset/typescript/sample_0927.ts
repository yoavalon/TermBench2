function transform(x: number, y: number, z: number, a: number, b: number, c: number): void {
    [x, y, z] = [a * x + b * y + c * z, b * x + a * y, c * x + y];
    transform(x, y, z, a, b, c);
}

transform(1, 1, 1, 1.5, -0.5, 0);