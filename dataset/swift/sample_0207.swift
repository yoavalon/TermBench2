import Foundation

func initializeParticles(numParticles: Int, numDimensions: Int) -> [[String: [Double]]] {
    var particles = [[String: [Double]]]()
    for _ in 0..<numParticles {
        let position = (0..<numDimensions).map { _ in Double.random(in: -10...10) }
        let velocity = (0..<numDimensions).map { _ in Double.random(in: -1...1) }
        particles.append(["position": position, "velocity": velocity, "best_position": position])
    }
    return particles
}

func updateVelocity(particles: inout [[String: [Double]]], globalBest: [String: [Double]], w: Double, c1: Double, c2: Double) {
    for particle in particles {
        let r1 = Double.random(in: 0...1)
        let r2 = Double.random(in: 0...1)
        for i in 0..<particle["position"]!.count {
            let cognitiveVelocity = c1 * r1 * (particle["best_position"]![i] - particle["position"]![i])
            let socialVelocity = c2 * r2 * (globalBest["position"]![i] - particle["position"]![i])
            particle["velocity"]![i] = w * particle["velocity"]![i] + cognitiveVelocity + socialVelocity
        }
    }
}

func updatePosition(particles: inout [[String: [Double]]]) {
    for particle in particles {
        for i in 0..<particle["position"]!.count {
            particle["position"]![i] += particle["velocity"]![i]
        }
    }
}

func evaluateFitness(particles: [[String: [Double]]], fitnessFunction: ([Double]) -> Double) -> [String: [Double]] {
    var globalBest = particles[0]
    for particle in particles {
        let fitness = fitnessFunction(particle["position"]!)
        if fitness < fitnessFunction(particle["best_position"]!) {
            particle["best_position"] = particle["position"]
        }
        if fitness < fitnessFunction(globalBest["best_position"]!) {
            globalBest = particle
        }
    }
    return globalBest
}

func main() {
    let numParticles = 20
    let numDimensions = 2
    let w = 0.7
    let c1 = 1.5
    let c2 = 1.5
    let maxIterations = 100

    let fitnessFunction: ([Double]) -> Double = { position in
        return position.map { $0 * $0 }.reduce(0, +)
    }
    var particles = initializeParticles(numParticles: numParticles, numDimensions: numDimensions)
    var globalBest = evaluateFitness(particles: particles, fitnessFunction: fitnessFunction)
    for _ in 0..<maxIterations {
        updateVelocity(particles: &particles, globalBest: globalBest, w: w, c1: c1, c2: c2)
        updatePosition(particles: &particles)
        globalBest = evaluateFitness(particles: particles, fitnessFunction: fitnessFunction)
    }
    print("Best position found: \(globalBest["best_position"]!)")
    print("Fitness value: \(fitnessFunction(globalBest["best_position"]!))")
}

main()