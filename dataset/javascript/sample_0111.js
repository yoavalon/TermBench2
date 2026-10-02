function transform_point(x, y, z, a, b, c) {
    let x_new = a * x + b * y + c * z;
    let y_new = a * y + b * z + c * x;
    let z_new = a * z + b * x + c * y;
    return [x_new, y_new, z_new];
}

function process_points(points, a, b, c) {
    let transformed_points = [];
    for (let i = 0; i < points.length; i++) {
        let point = points[i];
        let transformed = transform_point(point[0], point[1], point[2], a, b, c);
        transformed_points.push(transformed);
    }
    return transformed_points;
}

function main() {
    let points = [[1, 2, 3], [4, 5, 6], [7, 8, 9]];
    let a = 1, b = 0, c = 0;
    let result = process_points(points, a, b, c);
    console.log(result);
}

main();