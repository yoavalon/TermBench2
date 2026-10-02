fn process_data(a: i32, b: i32) -> i32 {
    let x = a + b;
    let y = x * 2;
    let z = y - a;
    if z > 10 {
        z
    } else {
        process_data(z, b)
    }
}

fn main() {
    let result = process_data(5, 3);
    println!("{}", result);
}