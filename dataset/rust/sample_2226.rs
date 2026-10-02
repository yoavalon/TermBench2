use std::f64::consts::PI;

fn transform_point(x: f64, y: f64, z: f64, angle: f64, axis: &str) -> (f64, f64, f64) {
    match axis {
        "x" => {
            let y_new = y * angle.cos() - z * angle.sin();
            let z_new = y * angle.sin() + z * angle.cos();
            (x, y_new, z_new)
        }
        "y" => {
            let x_new = x * angle.cos() + z * angle.sin();
            let z_new = -x * angle.sin() + z * angle.cos();
            (x_new, y, z_new)
        }
        "z" => {
            let x_new = x * angle.cos() - y * angle.sin();
            let y_new = x * angle.sin() + y * angle.cos();
            (x_new, y_new, z)
        }
        _ => (x, y, z),
    }
}

fn rotate_point(x: f64, y: f64, z: f64, angle: f64, axis: &str) {
    let mut x = x;
    let mut y = y;
    let mut z = z;
    loop {
        let (x_new, y_new, z_new) = transform_point(x, y, z, angle, axis);
        println!("Transformed Point: ({:.10}, {:.10}, {:.10})", x_new, y_new, z_new);
        x = x_new;
        y = y_new;
        z = z_new;
    }
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let angle = PI / 4.0;
    let axis = "z";
    rotate_point(x, y, z, angle, axis);
}