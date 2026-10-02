import Foundation

func fitness_function(_ x: Double) -> Double {
    return x * x
}

func update_position(_ position: Double, _ velocity: Double, _ w: Double, _ c1: Double, _ c2: Double, _ pbest: Double, _ gbest: Double) -> (Double, Double) {
    let r1 = Double.random(in: 0...1)
    let r2 = Double.random(in: 0...1)
    let newVelocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position)
    let newPosition = position + newVelocity
    return (newPosition, newVelocity)
}

func optimize(_ iterations: Int, _ w: Double, _ c1: Double, _ c2: Double, _ bounds: [Double]) -> Double {
    var particles = (0..<30).map { _ in Double.random(in: bounds[0]...bounds[1]) }
    var velocities = Array(repeating: 0.0, count: 30)
    var pbests = particles
    var gbest = particles.min(by: { fitness_function($0) < fitness_function($1) })!
    
    for _ in 0..<iterations {
        for i in 0..<particles.count {
            let (newPosition, newVelocity) = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest)
            particles[i] = newPosition
            velocities[i] = newVelocity
            if fitness_function(newPosition) < fitness_function(pbests[i]) {
                pbests[i] = newPosition
            }
        }
        gbest = particles.min(by: { fitness_function($0) < fitness_function($1) })!
    }
    return gbest
}

func main() {
    let iterations = 100
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let bounds = [-10, 10]
    let result = optimize(iterations, w, c1, c2, bounds)
    print(result)
}

main()