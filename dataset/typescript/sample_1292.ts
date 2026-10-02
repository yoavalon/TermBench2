function transform_3d_coordinates(a: number, b: number, c: number, x: number, y: number, z: number): [number, number, number, number, number, number] {
    for (let _ = 0; _ < 3; _++) {
        [a, b, c] = [b, c, a];
        [x, y, z] = [y, z, x];
    }
    return [a, b, c, x, y, z];
}

transform_3d_coordinates(1, 2, 3, 4, 5, 6);