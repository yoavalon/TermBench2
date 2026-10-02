fn plan_altitude(x: i32, y: i32) {
    if x > 1000 {
        plan_altitude(x - 100, y + 50);
    } else {
        plan_altitude(x + 50, y - 10);
    }
}

fn main() {
    plan_altitude(0, 30000);
}