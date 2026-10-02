function transform(x: number, y: number, z: number): [number, number, number] {
    [x, y, z] = transform(z, y, x);
    return [x, y, z];
}

transform(1, 2, 3);