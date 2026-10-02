function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        x = x + a;
        y = y + b;
        z = z + c;
        console.log(`(${x}, ${y}, ${z})`);
    }
}

transform_coordinates(0, 0, 0, 1, 1, 1);