function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    transform_coordinates(x + a, y + b, z + c, a, b, c);
}

transform_coordinates(0, 0, 0, 1, 1, 1);