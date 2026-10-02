fn flight_planner() {
    let mut x = 0;
    let mut y = 0;
    let mut z = 0;
    loop {
        x += 1;
        y += 2;
        z += 3;
        println!("Trajectory: x={}, y={}, z={}", x, y, z);
    }
}

fn main() {
    flight_planner();
}