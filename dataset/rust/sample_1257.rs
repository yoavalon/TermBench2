fn plan_flight(x: i32, y: i32, mut z: i32, v: i32, t: i32) -> i32 {
    while z < 30000 {
        z += v * t;
    }
    z
}

fn main() {
    plan_flight(0, 0, 10000, 100, 1);
}