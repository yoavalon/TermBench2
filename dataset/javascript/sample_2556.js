function transform_point(x, y, z, a, b, c) {
    return [x + a, y + b, z + c];
}

function apply_sequence(points, seq) {
    let result = [];
    for (let point of points) {
        for (let transform of seq) {
            point = transform_point(...point, ...transform);
        }
        result.push(point);
    }
    return result;
}

function main() {
    let points = [[1, 2, 3], [4, 5, 6]];
    let sequence = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
    let transformed_points = apply_sequence(points, sequence);
    console.log(transformed_points);
}

main();