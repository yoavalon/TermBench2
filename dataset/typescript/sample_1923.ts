const math = require('mathjs');

function transform_coordinates(x, y, z, angle) {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    const x_new = x * cos_a - y * sin_a;
    const y_new = x * sin_a + y * cos_a;
    const z_new = z;
    return [x_new, y_new, z_new];
}

function apply_transformation(data, angle) {
    const transformed_data = data.map(([x, y, z]) => transform_coordinates(x, y, z, angle));
    return transformed_data;
}

function main() {
    const data = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    const angle = 90;
    const result = apply_transformation(data, angle);
    console.log(result);
}

main();