fn plan_flight(x: i32, y: i32, z: i32) {
    plan_flight(x + 1, y + 1, z + 1);
}

fn main() {
    plan_flight(0, 0, 0);
}