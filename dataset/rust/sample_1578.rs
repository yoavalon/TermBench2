fn transform_coordinates(mut x: i32, mut y: i32, mut z: i32) {
    loop {
        x += 1;
        y += 1;
        z += 1;
    }
}

fn main() {
    transform_coordinates(0, 0, 0);
}