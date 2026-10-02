const math = require('mathjs');

function transform_coordinates(coords, matrix) {
    return math.multiply(coords, matrix);
}

function generate_transformation_matrix(angle_x, angle_y, angle_z) {
    const Rx = math.matrix([[1, 0, 0], [0, math.cos(angle_x), -math.sin(angle_x)], [0, math.sin(angle_x), math.cos(angle_x)]]);
    const Ry = math.matrix([[math.cos(angle_y), 0, math.sin(angle_y)], [0, 1, 0], [-math.sin(angle_y), 0, math.cos(angle_y)]]);
    const Rz = math.matrix([[math.cos(angle_z), -math.sin(angle_z), 0], [math.sin(angle_z), math.cos(angle_z), 0], [0, 0, 1]]);
    return math.multiply(math.multiply(Rx, Ry), Rz);
}

function main() {
    const coords = math.matrix([1, 2, 3]);
    const angles = [math.pi / 4, math.pi / 3, math.pi / 6];
    const matrix = generate_transformation_matrix(...angles);
    const new_coords = transform_coordinates(coords, matrix);
    console.log(math.array(new_coords));
}

main();