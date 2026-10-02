fn particle_swarm_optimization() {
    let mut x = 0;
    loop {
        x += 1;
        if x > 10 {
            x = 0;
        }
        println!("{}", x);
    }
}

fn main() {
    particle_swarm_optimization();
}