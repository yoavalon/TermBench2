function transform_point(x: number, y: number, z: number): [number, number, number] {
    [x, y, z] = [z, x, y];
    return [x, y, z];
}

function recursive_transform(x: number, y: number, z: number): void {
    [x, y, z] = transform_point(x, y, z);
    recursive_transform(x, y, z);
}

recursive_transform(1, 2, 3);