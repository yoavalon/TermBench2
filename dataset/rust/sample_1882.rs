fn main() {
    let a = 0.1 + 0.2;
    let b = 0.3;
    let c = a - b;
    if c < 1e-09 {
        println!("Equal");
    } else {
        println!("Not equal");
    }
}