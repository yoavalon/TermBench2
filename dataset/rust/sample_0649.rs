fn f(x: i32, y: i32, z: i32) {
    if x <= 0 || y <= 0 || z <= 0 {
        return;
    }
    println!("Altitude: {}, Speed: {}, Time: {}", x, y, z);
    f(x - 1, y - 1, z - 1);
}

fn main() {
    f(10, 20, 30);
}