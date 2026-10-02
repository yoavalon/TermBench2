fn particle_swarm_optimization() {
    let mut x = 0.5;
    let mut v = 0.1;
    let mut pbest = x;
    let mut gbest = x;
    loop {
        v = v + 0.1 * (gbest - x);
        x = x + v;
        if x < pbest {
            pbest = x;
        }
        if x < gbest {
            gbest = x;
        }
    }
}

fn main() {
    particle_swarm_optimization();
}