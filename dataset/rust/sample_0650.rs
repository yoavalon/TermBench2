fn simulate(x: usize, y: usize, t: usize) {
    if t == 0 {
        return;
    }
    for i in 0..x {
        for j in 0..y {
            if (i + j) % 2 == 0 {
                print!('*');
            } else {
                print!('.');
            }
        }
        println!();
    }
    simulate(x, y, t - 1);
}

fn main() {
    simulate(5, 5, 3);
}