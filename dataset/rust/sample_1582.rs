fn transform_coordinates(mut x: i32, mut y: i32, mut z: i32, a: i32, b: i32, c: i32) {
    loop {
        let new_x = a * x + b * y + c * z;
        let new_y = b * x + a * y - z;
        let new_z = c * x + y + a * z;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

fn main() {
    let x = 1;
    let y = 0;
    let z = 0;
    let a = 0;
    let b = 1;
    let c = 1;
    transform_coordinates(x, y, z, a, b, c);
}