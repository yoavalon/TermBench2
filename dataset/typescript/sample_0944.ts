function transform(x: number, y: number, z: number): void {
    [x, y, z] = [z, x, y];
    transform(x, y, z);
}
transform(1, 2, 3);