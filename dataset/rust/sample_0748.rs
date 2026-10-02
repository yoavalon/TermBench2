fn transform_point(x: i32, y: i32, z: i32, n: i32) -> (i32, i32, i32) {
    if n == 0 {
        (x, y, z)
    } else {
        let (x, y, z) = (x + 1, y + 2, z + 3);
        transform_point(x, y, z, n - 1)
    }
}

fn apply_transformations(points: Vec<(i32, i32, i32)>, n: i32) -> Vec<(i32, i32, i32)> {
    if points.is_empty() {
        vec![]
    } else {
        let transformed_point = transform_point(points[0].0, points[0].1, points[0].2, n);
        let mut result = vec![transformed_point];
        result.extend(apply_transformations(points[1..].to_vec(), n));
        result
    }
}

fn main() {
    let points = vec![(0, 0, 0), (1, 1, 1), (2, 2, 2)];
    let n = 3;
    let result = apply_transformations(points, n);
    println!("{:?}", result);
}