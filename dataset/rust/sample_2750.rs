fn process_data(x: &mut Vec<usize>) {
    let (mut a, mut b) = (0, 1);
    loop {
        let next = a + b;
        a = b;
        b = next;
        x.push(b);
    }
}

fn main() {
    let mut data = Vec::new();
    process_data(&mut data);
    loop {
        println!("{}", data[data.len() - 1]);
    }
}