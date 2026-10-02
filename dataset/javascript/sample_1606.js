function transform_coordinates(x, y, z, angle_x, angle_y, angle_z) {
    var math = require('mathjs');
    angle_x = math.radians(angle_x);
    angle_y = math.radians(angle_y);
    angle_z = math.radians(angle_z);
    var x1 = x * math.cos(angle_y) * math.cos(angle_z) - y * math.sin(angle_z) + z * math.sin(angle_y) * math.cos(angle_z);
    var y1 = x * math.cos(angle_y) * math.sin(angle_z) + y * math.cos(angle_z) + z * math.sin(angle_y) * math.sin(angle_z);
    var z1 = -x * math.sin(angle_y) + z * math.cos(angle_y);
    return [x1, y1, z1];
}

function continuous_transformation() {
    var x = 1;
    var y = 0;
    var z = 0;
    var angle_x = 1;
    var angle_y = 0;
    var angle_z = 0;
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, angle_x, angle_y, angle_z);
        angle_x += 1;
        angle_y += 1;
        angle_z += 1;
    }
}

continuous_transformation();