fn main() {
    let mut a = vec![1];
    loop {
        let b = a.last().unwrap();
        a.push(b + 1);
        println!("{}", a.last().unwrap());
    }
}