fn simulate() {
    let mut data = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9];
    loop {
        for i in 0..data.len() {
            data[i] = (data[i] + 0.01) % 1.0;
            println!("{:?}", data);
        }
    }
}

fn main() {
    simulate();
}