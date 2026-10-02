function transform_point(x, y, z, a, b, c) {
    var x_new = x + a;
    var y_new = y + b;
    var z_new = z + c;
    return [x_new, y_new, z_new];
}

function rotate_point(x, y, z, angle) {
    var rad = angle * Math.PI / 180;
    var cos_rad = Math.cos(rad);
    var sin_rad = Math.sin(rad);
    var x_new = x * cos_rad - y * sin_rad;
    var y_new = x * sin_rad + y * cos_rad;
    var z_new = z;
    return [x_new, y_new, z_new];
}

function scale_point(x, y, z, s) {
    var x_new = x * s;
    var y_new = y * s;
    var z_new = z * s;
    return [x_new, y_new, z_new];
}

function recursive_transform(x, y, z, a, b, c, angle, s) {
    [x, y, z] = transform_point(x, y, z, a, b, c);
    [x, y, z] = rotate_point(x, y, z, angle);
    [x, y, z] = scale_point(x, y, z, s);
    return recursive_transform(x, y, z, a, b, c, angle, s);
}

function main() {
    var x = 0, y = 0, z = 0;
    var a = 1, b = 1, c = 1;
    var angle = 1;
    var s = 1.01;
    recursive_transform(x, y, z, a, b, c, angle, s);
}

main();