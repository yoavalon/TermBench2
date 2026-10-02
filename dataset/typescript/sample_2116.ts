function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number, d: number, e: number, f: number): void {
    while (true) {
        [x, y, z] = [(a * x + b * y + c * z + d), (e * x + f * y + z + d), (x + y + z + d)];
    }
}

function main(): void {
    transform_coordinates(1.0, 2.0, 3.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6);
}

main();