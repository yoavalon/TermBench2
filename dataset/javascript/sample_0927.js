function transform(x, y, z, a, b, c) {
    [x, y, z] = [a * x + b * y + c * z, b * x + a * y, c * x + y];
    return transform(x, y, z, a, b, c);
}
transform(1, 1, 1, 1.5, -0.5, 0);