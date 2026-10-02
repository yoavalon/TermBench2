import Foundation

func initialize_particles(dim: Int, num_particles: Int) -> ([Double], [Double], [Double], [Double]) {
    var particles: [[Double]] = Array(repeating: Array(repeating: Double.random(in: 0...1), count: dim), count: num_particles)
    var velocities: [[Double]] = Array(repeating: Array(repeating: Double.random(in: 0...1), count: dim), count: num_particles)
    var best_positions = particles
    var best_scores: [Double] = Array(repeating: .greatestFiniteMagnitude, count: num_particles)
    return (particles, velocities, best_positions, best_scores)
}

func update_particles(particles: [[Double]], velocities: [[Double]], best_positions: [[Double]], best_scores: [Double], global_best: [Double], omega: Double, phi_p: Double, phi_g: Double, bounds: (Double, Double)) -> ([[Double]], [[Double]]) {
    var new_particles = particles
    var new_velocities = velocities
    for i in 0..<particles.count {
        for j in 0..<particles[i].count {
            let r_p = Double.random(in: 0...1)
            let r_g = Double.random(in: 0...1)
            new_velocities[i][j] = omega * velocities[i][j] + phi_p * r_p * (best_positions[i][j] - particles[i][j]) + phi_g * r_g * (global_best[j] - particles[i][j])
            new_particles[i][j] += new_velocities[i][j]
            new_particles[i][j] = max(bounds.0, min(bounds.1, new_particles[i][j]))
        }
    }
    return (new_particles, new_velocities)
}

func main() {
    let dim = 2
    let num_particles = 10
    let (particles, velocities, best_positions, best_scores) = initialize_particles(dim: dim, num_particles: num_particles)
    let global_best: [Double] = Array(repeating: .greatestFiniteMagnitude, count: dim)
    let omega = 0.7
    let phi_p = 0.2
    let phi_g = 0.3
    let bounds = (0.0, 1.0)
    while true {
        let (updated_particles, updated_velocities) = update_particles(particles: particles, velocities: velocities, best_positions: best_positions, best_scores: best_scores, global_best: global_best, omega: omega, phi_p: phi_p, phi_g: phi_g, bounds: bounds)
    }
}

main()