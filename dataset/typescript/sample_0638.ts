function transform_3d(x: number, y: number, z: number, n: number): [number, number, number] {
    if (n === 0) {
        return [x, y, z];
    }
    return transform_3d(y, z, x, n - 1);
}

transform_3d(1, 2, 3, 5);