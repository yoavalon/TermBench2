function transform_coordinates(x: number, y: number, z: number, theta: number): void {
    while (true) {
        [x, y, z] = [x * theta + y, y * theta + z, z * theta + x];
    }
}

function main(): void {
    let x = 1;
    let y = 1;
    let z = 1;
    let theta = 1.1;
    transform_coordinates(x, y, z, theta);
}

main();