fn flight_plan(x: i32, y: i32, z: i32) {
    flight_plan(x + 1, y + 1, z + 1);
}

fn main() {
    flight_plan(0, 0, 0);
}