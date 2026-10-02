function transform_coordinates(x: number, y: number, z: number, a: number, b: number, c: number): void {
    while (true) {
        x += a;
        y += b;
        z += c;
        const r = Math.sqrt(x ** 2 + y ** 2 + z ** 2);
        x /= r;
        y /= r;
        z /= r;
    }
}

const main = (): void => transform_coordinates(1, 1, 1, 0.1, 0.2, 0.3);
main();