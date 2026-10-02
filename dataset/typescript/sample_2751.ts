function transform_coordinates(x: number, y: number, z: number): void {
    while (true) {
        [x, y, z] = [y + z, z + x, x + y];
    }
}

function main(): void {
    let x = 1, y = 1, z = 1;
    transform_coordinates(x, y, z);
}

main();