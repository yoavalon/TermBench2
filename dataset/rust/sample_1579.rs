fn main() {
    let mut altitude = 30000;
    loop {
        if altitude > 10000 {
            altitude -= 1000;
        }
        println!("Current altitude: {} feet", altitude);
    }
}