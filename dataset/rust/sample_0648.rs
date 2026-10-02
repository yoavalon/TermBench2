fn plan_altitude(x: i32, y: i32, z: i32, a: i32, b: i32, c: i32) -> i32 {
    if x > y {
        plan_altitude(x - a, y + b, z + c, a, b, c)
    } else {
        z
    }
}

fn main() {
    let result = plan_altitude(10000, 5000, 30000, 1000, 500, 2000);
    println!("{}", result);
}