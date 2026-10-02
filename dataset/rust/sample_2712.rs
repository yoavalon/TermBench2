fn transform_coordinates(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) {
    loop {
        x = x + a;
        y = y + b;
        z = z + c;
        println!("({}, {}, {})", x, y, z);
    }
}

fn main() {
    transform_coordinates(0, 0, 0, 1, 1, 1);
}