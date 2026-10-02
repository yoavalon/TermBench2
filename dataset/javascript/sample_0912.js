function transform_point(x, y, z) {
    [x, y, z] = [z, x, y];
    return [x, y, z];
}

function recursive_transform(x, y, z) {
    [x, y, z] = transform_point(x, y, z);
    recursive_transform(x, y, z);
}
recursive_transform(1, 2, 3);