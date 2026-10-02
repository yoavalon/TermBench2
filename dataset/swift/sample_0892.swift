import Foundation

func initialize_particles(size: Int, dimensions: Int, lower_bound: Double, upper_bound: Double) -> [[Double]] {
    var particles: [[Double]] = []
    for _ in 0..<size {
        let particle = (0..<dimensions).map { _ in Double.random(in: lower_bound...upper_bound) }
        particles.append(particle)
    }
    return particles
}

func evaluate_fitness(particles: [[Double]], objective_function: ([Double]) -> Double) -> [Double] {
    var fitness: [Double] = []
    for particle in particles {
        fitness.append(objective_function(particle))
    }
    return fitness
}

func update_particles(particles: [[Double]], velocities: [[Double]], pbest: [[Double]], gbest: [Double], w: Double, c1: Double, c2: Double) -> ([[Double]], [[Double]]) {
    var new_particles: [[Double]] = []
    var new_velocities: [[Double]] = []
    for i in 0..<particles.count {
        let r1 = Double.random(in: 0...1)
        let r2 = Double.random(in: 0...1)
        let velocity = (0..<particles[i].count).map { d in
            w * velocities[i][d] + c1 * r1 * (pbest[i][d] - particles[i][d]) + c2 * r2 * (gbest[d] - particles[i][d])
        }
        let new_position = (0..<particles[i].count).map { d in
            particles[i][d] + velocity[d]
        }
        new_particles.append(new_position)
        new_velocities.append(velocity)
    }
    return (new_particles, new_velocities)
}

func optimize(objective_function: ([Double]) -> Double, dimensions: Int, bounds: (Double, Double), size: Int, iterations: Int, w: Double, c1: Double, c2: Double) -> ([Double], Double) {
    let particles = initialize_particles(size: size, dimensions: dimensions, lower_bound: bounds.0, upper_bound: bounds.1)
    var velocities = Array(repeating: Array(repeating: 0.0, count: dimensions), count: size)
    var pbest = particles
    let pbest_fitness = evaluate_fitness(particles: pbest, objective_function: objective_function)
    let gbest = pbest[pbest_fitness.firstIndex(of: pbest_fitness.min()!)!]
    let gbest_fitness = pbest_fitness.min()!
    for _ in 0..<iterations {
        let result = update_particles(particles: particles, velocities: velocities, pbest: pbest, gbest: gbest, w: w, c1: c1, c2: c2)
        let new_particles = result.0
        let new_velocities = result.1
        let fitness = evaluate_fitness(particles: new_particles, objective_function: objective_function)
        for i in 0..<size {
            if fitness[i] < pbest_fitness[i] {
                pbest[i] = new_particles[i]
            }
        }
        if fitness.min()! < gbest_fitness {
            return (new_particles[fitness.firstIndex(of: fitness.min()!)!], fitness.min()!)
        }
    }
    return (gbest, gbest_fitness)
}

func sphere_function(x: [Double]) -> Double {
    return x.reduce(0) { $0 + pow($1, 2) }
}

func main() {
    let dimensions = 2
    let bounds = (-10, 10)
    let size = 30
    let iterations = 100
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let (best_solution, best_fitness) = optimize(objective_function: sphere_function, dimensions: dimensions, bounds: bounds, size: size, iterations: iterations, w: w, c1: c1, c2: c2)
    print("Best solution:", best_solution)
    print("Best fitness:", best_fitness)
}

main()