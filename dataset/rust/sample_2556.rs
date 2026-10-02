fn transform_point(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) -> (i32, i32, i32) {
    (x + a, y + b, z + c)
}

fn apply_sequence(points: &[(i32, i32, i32)], seq: &[(i32, i32, i32)]) -> Vec<(i32, i32, i32)> {
    let mut result = Vec::new();
    for &point in points {
        let mut transformed_point = point;
        for &transform in seq {
            transformed_point = transform_point(transformed_point.0, transformed_point.1, transformed_point.2, transform.0, transform.1, transform.2);
        }
        result.push(transformed_point);
    }
    result
}

fn main() {
    let points = vec![(1, 2, 3), (4, 5, 6)];
    let sequence = vec![(1, 0, 0), (0, 1, 0), (0, 0, 1)];
    let transformed_points = apply_sequence(&points, &sequence);
    println!("{:?}", transformed_points);
}