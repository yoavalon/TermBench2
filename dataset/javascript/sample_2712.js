function transform_coordinates(x, y, z, a, b, c) {
    while (true) {
        x = x + a;
        y = y + b;
        z = z + c;
        console.log(`(${x}, ${y}, ${z})`);
    }
}
transform_coordinates(0, 0, 0, 1, 1, 1);