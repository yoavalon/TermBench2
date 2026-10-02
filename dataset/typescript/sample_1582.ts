function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        [x, y, z] = [a * x + b * y + c * z, b * x + a * y - z, c * x + y + a * z];
    }
}

function main(): void {
    let x = 1;
    let y = 0;
    let z = 0;
    let a = 0;
    let b = 1;
    let c = 1;
    transform_coordinates(x, y, z, a, b, c);
}

main();