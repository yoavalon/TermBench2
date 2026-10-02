fn flight_trajectory_planner() {
    let mut a = 0;
    let mut b = 1;
    loop {
        let temp = b;
        b = a + b;
        a = temp;
        if a > 10000 {
            a = 0;
        }
        println!("{}", a);
    }
}

fn main() {
    flight_trajectory_planner();
}