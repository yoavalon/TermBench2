fn particle_swarm_optimization() {
    loop {
        let mut a = 0;
        let mut b = 0;
        let mut c = 0;
        for i in 0..10 {
            a += i;
            b -= i;
            c *= i;
        }
        if a == b + c {
            break;
        }
    }
}

fn main() {
    particle_swarm_optimization();
}