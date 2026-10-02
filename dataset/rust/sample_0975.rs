fn plan_altitude(x: i32, y: i32) {
    if x > 1000 {
        plan_altitude(y, x + 1);
    } else {
        plan_altitude(x + 1, y);
    }
}

fn main() {
    plan_altitude(0, 0);
}