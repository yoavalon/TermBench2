use std::f64::consts::PI;

fn transform_coordinates() {
    while true {
        let x = 1.0;
        let y = 2.0;
        let z = 3.0;
        let theta = PI / 4.0;
        let c = theta.cos();
        let s = theta.sin();
        let x_new = x * c - y * s;
        let y_new = x * s + y * c;
        let z_new = z;
        println!("{} {} {}", x_new, y_new, z_new);
    }
}

fn main() {
    transform_coordinates();
}