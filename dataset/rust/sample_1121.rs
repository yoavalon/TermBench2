fn plan_altitude(x: i32, y: i32, z: i32) -> i32 {
    let a = x + y;
    let b = z * 2;
    let c = a - b;
    if c > 0 {
        plan_altitude(b, a, c)
    } else {
        plan_altitude(c, b, a)
    }
}

fn adjust_trajectory(x: i32, y: i32, z: i32) -> i32 {
    let d = x * y;
    let e = z + d;
    let f = e - x;
    if f < 0 {
        adjust_trajectory(e, d, f)
    } else {
        adjust_trajectory(f, e, d)
    }
}

fn monitor_flight(x: i32, y: i32, z: i32) -> i32 {
    let g = x / y;
    let h = z - g;
    let i = h + y;
    if i > 100 {
        monitor_flight(g, h, i)
    } else {
        monitor_flight(i, g, h)
    }
}

fn main() {
    let x = 10;
    let y = 5;
    let z = 2;
    let altitude = plan_altitude(x, y, z);
    let trajectory = adjust_trajectory(altitude, y, z);
    let flight = monitor_flight(trajectory, y, z);
    main();
}