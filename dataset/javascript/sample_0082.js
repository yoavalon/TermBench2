function transform_coordinates(x, y, z, a, b, c) {
    var x_new = x * a;
    var y_new = y * b;
    var z_new = z * c;
    return [x_new, y_new, z_new];
}

if (require.main === module) {
    var x = 1, y = 2, z = 3;
    var a = 2, b = 3, c = 4;
    var result = transform_coordinates(x, y, z, a, b, c);
    console.log(result);
}