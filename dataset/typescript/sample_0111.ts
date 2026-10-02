function transform_point(x: number, y: number, z: number, a: number, b: number, c: number): [number, number, number] {
    let x_new = a * x + b * y + c * z;
    let y_new = a * y + b * z + c * x;
    let z_new = a * z + b * x + c * y;
    return [x_new, y_new, z_new];
}

function process_points(points: [number, number, number][], a: number, b: number, c: number): [number, number, number][] {
    let transformed_points: [number, number, number][] = [];
    for (let point of points) {
        let transformed = transform_point(point[0], point[1], point[2], a, b, c);
        transformed_points.push(transformed);
    }
    return transformed_points;
}

function main() {
    let points: [number, number, number][] = [(1, 2, 3), (4, 5, 6), (7, 8, 9)];
    let a: number = 1, b: number = 0, c: number = 0;
    let result: [number, number, number][] = process_points(points, a, b, c);
    console.log(result);
}

main();