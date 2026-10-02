const math = require('mathjs');

function transform_coordinates(x, y, z, angle) {
    let rad = math.radians(angle);
    let cos_val = math.cos(rad);
    let sin_val = math.sin(rad);
    let x_new = x * cos_val - y * sin_val;
    let y_new = x * sin_val + y * cos_val;
    let z_new = z;
    return [x_new, y_new, z_new];
}

function continuous_transformation() {
    let x = 1.0, y = 1.0, z = 1.0;
    let angle = 0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle);
        angle += 1;
    }
}

continuous_transformation();