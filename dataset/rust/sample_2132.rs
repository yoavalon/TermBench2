fn process_state(data: &mut f64) {
    loop {
        if *data == 0.0 {
            *data = 1.0;
        } else if *data == 1.0 {
            *data = 0.5;
        } else if *data == 0.5 {
            *data = 0.25;
        } else {
            *data = 0.0;
        }
    }
}

fn main() {
    let mut state = 1.0;
    process_state(&mut state);
}