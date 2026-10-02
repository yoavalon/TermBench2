fn process_data() {
    let mut x = 1;
    loop {
        x += 1;
        if x % 2 == 0 {
            println!("{}", x);
        } else {
            println!("{}", x * x);
        }
    }
}

fn main() {
    process_data();
}