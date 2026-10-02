use rand::prelude::*;
use std::f64;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize) -> Self {
        let position = (0..dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
        let velocity = (0..dimensions).map(|_| rand::random::<f64>() * 2.0 - 1.0).collect();
        Particle {
            position,
            velocity,
            best_position: position.clone(),
            best_score: f64::INFINITY,
        }
    }

    fn update_velocity(&mut self, global_best: &[f64], inertia: f64, cognitive: f64, social: f64) {
        for i in 0..self.position.len() {
            let r1 = rand::random::<f64>();
            let r2 = rand::random::<f64>();
            self.velocity[i] = inertia * self.velocity[i] + cognitive * r1 * (self.best_position[i] - self.position[i]) + social * r2 * (global_best[i] - self.position[i]);
        }
    }

    fn update_position(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
    }

    fn evaluate(&mut self, fitness_function: &dyn Fn(&[f64]) -> f64) {
        self.best_score = fitness_function(&self.position);
        if self.best_score < self.best_score {
            self.best_score = self.best_score;
            self.best_position = self.position.clone();
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    fitness_function: Box<dyn Fn(&[f64]) -> f64>,
    max_iterations: usize,
    inertia: f64,
    cognitive: f64,
    social: f64,
    global_best: Option<Vec<f64>>,
    global_best_score: f64,
}

impl Swarm {
    fn new(size: usize, dimensions: usize, fitness_function: Box<dyn Fn(&[f64]) -> f64>, max_iterations: usize, inertia: f64, cognitive: f64, social: f64) -> Self {
        Swarm {
            particles: (0..size).map(|_| Particle::new(dimensions)).collect(),
            fitness_function,
            max_iterations,
            inertia,
            cognitive,
            social,
            global_best: None,
            global_best_score: f64::INFINITY,
        }
    }

    fn update_global_best(&mut self) {
        for particle in &self.particles {
            if particle.best_score < self.global_best_score {
                self.global_best_score = particle.best_score;
                self.global_best = Some(particle.best_position.clone());
            }
        }
    }

    fn optimize(&mut self) {
        for _ in 0..self.max_iterations {
            for particle in &mut self.particles {
                if let Some(ref global_best) = self.global_best {
                    particle.update_velocity(global_best, self.inertia, self.cognitive, self.social);
                }
                particle.update_position();
                particle.evaluate(&self.fitness_function);
            }
            self.update_global_best();
        }
    }
}

fn sphere_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn main() {
    let dimensions = 2;
    let size = 30;
    let max_iterations = 100;
    let inertia = 0.5;
    let cognitive = 1.5;
    let social = 1.5;
    let mut swarm = Swarm::new(size, dimensions, Box::new(sphere_function), max_iterations, inertia, cognitive, social);
    swarm.optimize();
    if let Some(ref best_position) = swarm.global_best {
        println!("Best position: {:?}", best_position);
    }
    println!("Best score: {}", swarm.global_best_score);
}