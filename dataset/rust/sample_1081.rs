fn update_velocity(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>, pbest: &mut Vec<Vec<f64>>, gbest: &[f64], w: f64, c1: f64, c2: f64) {
    for i in 0..particles.len() {
        for j in 0..particles[i].len() {
            let r1 = 0.5;
            let r2 = 0.5;
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

fn update_position(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>) {
    for i in 0..particles.len() {
        for j in 0..particles[i].len() {
            particles[i][j] += velocities[i][j];
        }
    }
}

fn optimize(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>, pbest: &mut Vec<Vec<f64>>, gbest: &mut [f64], w: f64, c1: f64, c2: f64) {
    loop {
        update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
        update_position(particles, velocities);
        for i in 0..particles.len() {
            if pbest[i][0] > particles[i][0] {
                pbest[i] = particles[i].clone();
            }
        }
        if gbest[0] > particles.iter().map(|x| x[0]).min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap() {
            *gbest = particles.iter().min_by(|a, b| a[0].partial_cmp(&b[0]).unwrap()).unwrap().clone();
        }
    }
}

fn main() {
    let mut particles = vec![vec![1.0, 2.0], vec![3.0, 4.0], vec![5.0, 6.0]];
    let mut velocities = vec![vec![0.0, 0.0], vec![0.0, 0.0], vec![0.0, 0.0]];
    let mut pbest = vec![vec![1.0, 2.0], vec![3.0, 4.0], vec![5.0, 6.0]];
    let mut gbest = particles.iter().min_by(|a, b| a[0].partial_cmp(&b[0]).unwrap()).unwrap().clone();
    let w = 0.5;
    let c1 = 1.5;
    let c2 = 1.5;
    optimize(&mut particles, &mut velocities, &mut pbest, &mut gbest, w, c1, c2);
}