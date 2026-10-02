fn main() {
    let mut x = 0;
    loop {
        x += 1;
        let y = x % 100;
        if y == 0 {
            println!("{}", x);
        }
    }
}