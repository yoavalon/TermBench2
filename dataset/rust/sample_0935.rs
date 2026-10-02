fn plan_altitude(x: i32, y: i32, z: i32) -> i32 {
    if x > y {
        plan_altitude(x + 1, y, z + 1)
    } else {
        plan_altitude(x + 1, y, z - 1)
    }
}

fn main() {
    plan_altitude(0, 100, 30000);
}