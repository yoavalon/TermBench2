fn data_mutations() {
    let mut x = 1;
    let mut y = 1;
    loop {
        let new_x = x + y;
        let new_y = x;
        x = new_x;
        y = new_y;
        if x > 1000 {
            x = 1;
            y = 1;
        }
    }
}

fn main() {
    data_mutations();
}