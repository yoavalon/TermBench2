function transform(x, y, z) {
    [x, y, z] = [z, x, y];
    return transform(x, y, z);
}
transform(1, 2, 3);