fn plan_flight(x: i32, y: i32, z: i32, v: i32) -> (i32, i32, i32, i32) {
    if x == 0 || y == 0 || z == 0 || v == 0 {
        return (x, y, z, v);
    }
    let x = x - 1;
    let y = y - 1;
    let z = z - 1;
    let v = v - 1;
    plan_flight(x, y, z, v)
}

fn main() {
    let result = plan_flight(10, 10, 10, 10);
    println!("{:?}", result);
}