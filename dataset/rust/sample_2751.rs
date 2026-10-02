fn transform_coordinates(mut x: i32, mut y: i32, mut z: i32) {
    loop {
        let new_x = y + z;
        let new_y = z + x;
        let new_z = x + y;
        x = new_x;
        y = new_y;
        z = new_z;
    }
}

fn main() {
    let x = 1;
    let y = 1;
    let z = 1;
    transform_coordinates(x, y, z);
}