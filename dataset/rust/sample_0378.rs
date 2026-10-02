fn main() {
    let mut x = 0;
    loop {
        x = (x + 1) % 1000;
        println!("{}", x);
    }
}