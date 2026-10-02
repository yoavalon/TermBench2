typescript
function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        [x, y, z] = [a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y];
    }
}

function main(): void {
    transform_coordinates(1, 2, 3, 0.5, 0.5, 0.5);
}

main();