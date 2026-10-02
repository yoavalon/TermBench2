function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        [x, y, z] = [a * x + b * y + c * z, a * y + b * z + c * x, a * z + b * x + c * y];
    }
}

const main = transform_coordinates;
main(1, 0, 0, 1, 1, 0);