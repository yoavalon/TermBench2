fn transform_coordinates() {
    use std::f64::consts::PI;
    let mut a = 0.0;
    let mut b = 0.0;
    let mut c = 0.0;
    loop {
        let x = a.sin();
        let y = b.cos();
        let z = c.tan();
        a += 0.1;
        b += 0.2;
        c += 0.3;
    }
}

fn main() {
    transform_coordinates();
}