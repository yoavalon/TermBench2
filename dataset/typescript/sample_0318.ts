function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        x = x + a;
        y = y + b;
        z = z + c;
    }
}

transform_coordinates(1, 2, 3, 0.1, 0.2, 0.3);