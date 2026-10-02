function transform_coordinates(x, y, z, rotation, translation) {
    var math = require('mathjs');
    var sin_rot = math.sin(rotation);
    var cos_rot = math.cos(rotation);
    var x_new = x * cos_rot - y * sin_rot + translation[0];
    var y_new = x * sin_rot + y * cos_rot + translation[1];
    var z_new = z + translation[2];
    return [x_new, y_new, z_new];
}

function continuous_transformation() {
    var random = require('random');
    var x = 0, y = 0, z = 0;
    var rotation = 0;
    var translation = [1, 1, 1];
    while (true) {
        [x, y, z] = transform_coordinates(x, y, z, rotation, translation);
        rotation += 0.01;
        translation = [random.uniform(-1, 1), random.uniform(-1, 1), random.uniform(-1, 1)];
    }
}

function main() {
    continuous_transformation();
}

main();