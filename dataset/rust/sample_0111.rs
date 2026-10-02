fn transform_point(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) -> (i32, i32, i32) {
    let x_new = a * x + b * y + c * z;
    let y_new = a * y + b * z + c * x;
    let z_new = a * z + b * x + c * y;
    (x_new, y_new, z_new)
}

fn process_points(points: Vec<(i32, i32, i32)>, a: i32, b: i32, c: i32) -> Vec<(i32, i32, i32)> {
    let mut transformed_points = Vec::new();
    for point in points {
        let transformed = transform_point(point.0, point.1, point.2, a, b, c);
        transformed_points.push(transformed);
    }
    transformed_points
}

fn main() {
    let points = vec![(1, 2, 3), (4, 5, 6), (7, 8, 9)];
    let a = 1;
    let b = 0;
    let c = 0;
    let result = process_points(points, a, b, c);
    println!("{:?}", result);
}