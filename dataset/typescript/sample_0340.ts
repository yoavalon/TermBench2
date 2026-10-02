function transform_coordinates(x: number, y: number, z: number): void {
    while (true) {
        [x, y, z] = [z + y, x + z, y + x];
    }
}

function main(): void {
    transform_coordinates(1, 1, 1);
}

main();