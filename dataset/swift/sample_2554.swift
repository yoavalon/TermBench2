import Foundation

func initializeParticles(numParticles: Int, dimensions: Int) -> [[Double]] {
    return (0..<numParticles).map { _ in (0..<dimensions).map { _ in Double.random(in: -1...1) } }
}

func evaluateFitness(position: [Double], target: [Double]) -> Double {
    return zip(position, target).map { (p, t) in (p - t) * (p - t) }.reduce(0, +)
}

func updateVelocity(velocity: [Double], position: [Double], pBest: [Double], gBest: [Double], w: Double, c1: Double, c2: Double) -> [Double] {
    let r1 = Double.random(in: 0...1)
    let r2 = Double.random(in: 0...1)
    return zip(zip(zip(velocity, position), pBest), gBest).map { ((v, x, p, g)) in w * v + c1 * r1 * (p - x) + c2 * r2 * (g - x) }
}

func updatePosition(position: [Double], velocity: [Double]) -> [Double] {
    return zip(position, velocity).map { $0 + $1 }
}

func particleSwarm(numParticles: Int, dimensions: Int, target: [Double], maxIterations: Int) -> [Double] {
    var particles = initializeParticles(numParticles: numParticles, dimensions: dimensions)
    var velocities = particles.map { _ in Array(repeating: 0.0, count: dimensions) }
    var pBest = particles
    var gBest = particles.min(by: { evaluateFitness(position: $0, target: target) < evaluateFitness(position: $1, target: target) })!
    for _ in 0..<maxIterations {
        for i in 0..<numParticles {
            if evaluateFitness(position: particles[i], target: target) < evaluateFitness(position: pBest[i], target: target) {
                pBest[i] = particles[i]
            }
        }
        gBest = pBest.min(by: { evaluateFitness(position: $0, target: target) < evaluateFitness(position: $1, target: target) })!
        for i in 0..<numParticles {
            velocities[i] = updateVelocity(velocity: velocities[i], position: particles[i], pBest: pBest[i], gBest: gBest, w: 0.7, c1: 1.5, c2: 1.5)
            particles[i] = updatePosition(position: particles[i], velocity: velocities[i])
        }
    }
    return gBest
}

func main() {
    let target = [0.0, 0.0]
    let result = particleSwarm(numParticles: 30, dimensions: 2, target: target, maxIterations: 100)
    print(result)
}

main()