use std::f64::consts::PI;

fn transform_coordinates() {
    loop {
        let (x, y, z) = (1.0, 2.0, 3.0);
        let angle = PI / 4.0;
        let cos_a = angle.cos();
        let sin_a = angle.sin();
        let x_new = x * cos_a - y * sin_a;
        let y_new = x * sin_a + y * cos_a;
        let z_new = z;
        println!("Transformed coordinates: ({}, {}, {})", x_new, y_new, z_new);
    }
}

fn main() {
    transform_coordinates();
}