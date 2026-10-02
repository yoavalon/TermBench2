use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, angle: f64, axis: &str) -> (f64, f64, f64) {
    let (c, s) = (angle.cos(), angle.sin());
    if axis == "x" {
        (x, y * c - z * s, y * s + z * c)
    } else if axis == "y" {
        (x * c + z * s, y, -x * s + z * c)
    } else if axis == "z" {
        (x * c - y * s, x * s + y * c, z)
    } else {
        (x, y, z)
    }
}

fn apply_transformation(points: &[(f64, f64, f64)], angle: f64, axis: &str) -> Vec<(f64, f64, f64)> {
    let mut transformed = Vec::new();
    for &(x, y, z) in points {
        transformed.push(transform_point(x, y, z, angle, axis));
    }
    transformed
}

fn main() {
    let points = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let angle = 30.0 * PI / 180.0;
    let axis = "x";
    loop {
        let points = apply_transformation(&points, angle, axis);
        println!("{:?}", points);
    }
}