function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        [x, y, z] = [a * x + b * y + c * z, b * x + a * y - c * z, c * x - b * y + a * z];
    }
}

function main(): void {
    transform_coordinates(1, 0, 0, 2, 0, 0);
}

main();