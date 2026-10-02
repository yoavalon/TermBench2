function transform_coordinates(x, y, z, angle) {
    var math = require('mathjs');
    var cos_a = math.cos(angle);
    var sin_a = math.sin(angle);
    var x_new = x * cos_a - y * sin_a;
    var y_new = x * sin_a + y * cos_a;
    var z_new = z;
    return [x_new, y_new, z_new];
}

if (require.main === module) {
    var x = 1.0, y = 2.0, z = 3.0;
    var angle = Math.PI / 4;
    var result = transform_coordinates(x, y, z, angle);
    console.log(result[0], result[1], result[2]);
}