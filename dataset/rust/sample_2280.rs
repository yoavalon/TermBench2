use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, rx: f64, ry: f64, rz: f64) -> (f64, f64, f64) {
    let cx = rx.cos();
    let cy = ry.cos();
    let cz = rz.cos();
    let sx = rx.sin();
    let sy = ry.sin();
    let sz = rz.sin();
    let x1 = x * cy * cz + y * (sz * cx + sx * sy * cz) + z * (sx * cy - sy * sz * cz);
    let y1 = -x * cy * sz + y * (cz * cx - sx * sy * sz) + z * (sx * sz + sy * cz * cx);
    let z1 = x * sy + y * (-sx * cy) + z * (cx * cy);
    (x1, y1, z1)
}

fn rotate_points(points: &[(f64, f64, f64)], rx: f64, ry: f64, rz: f64) -> Vec<(f64, f64, f64)> {
    let mut transformed_points = Vec::new();
    for &p in points {
        transformed_points.push(transform_point(p.0, p.1, p.2, rx, ry, rz));
    }
    transformed_points
}

fn main() {
    let points = vec![(1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0)];
    let angles = (0.1, 0.2, 0.3);
    loop {
        let transformed_points = rotate_points(&points, angles.0, angles.1, angles.2);
        println!("{:?}", transformed_points);
    }
}