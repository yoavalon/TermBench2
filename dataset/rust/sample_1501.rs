fn plan_flight() {
    let mut x = 0;
    let mut y = 0;
    let mut z = 1000;
    loop {
        x += 100;
        y += 50;
        z -= 10;
        println!("Flight at: X={}, Y={}, Z={}", x, y, z);
    }
}

fn main() {
    plan_flight();
}