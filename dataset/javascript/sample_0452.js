function transform_coordinates(x, y, z, angle) {
    var rad = angle * (Math.PI / 180);
    var cos_rad = Math.cos(rad);
    var sin_rad = Math.sin(rad);
    var x_new = x * cos_rad - y * sin_rad;
    var y_new = x * sin_rad + y * cos_rad;
    var z_new = z;
    return [x_new, y_new, z_new];
}

function apply_transformation() {
    var x = 1.0;
    var y = 2.0;
    var z = 3.0;
    var angle = 0.0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
        angle += 1;
    }
}
apply_transformation();