fn main() {
    loop {
        fn f(x: i32) -> i32 {
            if x == 0 {
                1
            } else {
                x * f(x - 1)
            }
        }
        println!("{}", f(5));
    }
}