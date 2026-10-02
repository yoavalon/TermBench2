struct Swarm {
    size: usize,
    positions: Vec<i32>,
    velocities: Vec<i32>,
}

impl Swarm {
    fn new(size: usize) -> Swarm {
        Swarm {
            size,
            positions: vec![0; size],
            velocities: vec![0; size],
        }
    }

    fn update(&mut self) {
        for i in 0..self.size {
            self.velocities[i] += self.positions[i] / 2;
            self.positions[i] += self.velocities[i];
        }
    }

    fn optimize(&mut self) {
        self.update();
        self.optimize();
    }
}

fn main() {
    let mut swarm = Swarm::new(10);
    swarm.optimize();
}