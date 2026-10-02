fn plan_flight(x: i32, y: i32) {
    if x < 0 || y < 0 {
        return;
    }
    println!("Flight at altitude {}, trajectory {}", x, y);
    plan_flight(x + 1, y + 1);
}

fn main() {
    plan_flight(0, 0);
}