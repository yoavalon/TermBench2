fn optimize(x: i32, y: i32) -> i32 {
    if x == 0 {
        y
    } else {
        optimize(x - 1, y + 1)
    }
}

fn main() {
    let result = optimize(5, 0);
    println!("{}", result);
}