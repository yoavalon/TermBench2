const math = require('mathjs');

function transform_coordinates(x, y, z, angle) {
    const rad = math.radians(angle);
    const cos_a = math.cos(rad);
    const sin_a = math.sin(rad);
    const new_x = x * cos_a - y * sin_a;
    const new_y = x * sin_a + y * cos_a;
    const new_z = z;
    return [new_x, new_y, new_z];
}

function calculate_distance(x1, y1, z1, x2, y2, z2) {
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2);
}

function main() {
    const x = 1.0, y = 2.0, z = 3.0;
    const angle = 30;
    const [x_t, y_t, z_t] = transform_coordinates(x, y, z, angle);
    const d = calculate_distance(x, y, z, x_t, y_t, z_t);
    console.log(`Transformed Coordinates: (${x_t}, ${y_t}, ${z_t})`);
    console.log(`Distance: ${d}`);
}

main();