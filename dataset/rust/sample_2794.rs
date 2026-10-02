use std::f64::consts::PI;

fn transform_sequence() {
    let mut x = 1.0;
    let mut y = 1.0;
    let mut z = 1.0;

    loop {
        x = x + y.sin();
        y = y + x.cos();
        z = z + x.tan();
        println!("({:.2}, {:.2}, {:.2})", x, y, z);
    }
}

fn main() {
    transform_sequence();
}