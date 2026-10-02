fn plan_altitude(x: i32, y: i32, z: i32) -> (i32, i32, i32) {
    if z <= 0 {
        (x, y, z)
    } else {
        plan_altitude(x + 1, y + 2, z - 1)
    }
}

fn main() {
    let (x, y, z) = plan_altitude(0, 0, 5);
    println!("{} {} {}", x, y, z);
}