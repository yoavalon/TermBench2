import Foundation

func updateVelocity(p: Double, g: Double, v: Double, w: Double, c1: Double, c2: Double) -> Double {
    let r1 = Double.random(in: 0...1)
    let r2 = Double.random(in: 0...1)
    return w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p)
}

func updatePosition(p: Double, v: Double) -> Double {
    return p + v
}

func optimize(particles: [Double], velocities: [Double], bestPositions: [Double], globalBest: Double, w: Double, c1: Double, c2: Double) -> ([Double], [Double], [Double]) {
    var newParticles: [Double] = []
    var newVelocities: [Double] = []
    var newBestPositions: [Double] = []
    for i in 0..<particles.count {
        let v = updateVelocity(p: particles[i], g: globalBest, v: velocities[i], w: w, c1: c1, c2: c2)
        let p = updatePosition(p: particles[i], v: v)
        newParticles.append(p)
        newVelocities.append(v)
        if p < bestPositions[i] {
            newBestPositions.append(p)
        } else {
            newBestPositions.append(bestPositions[i])
        }
    }
    return (newParticles, newVelocities, newBestPositions)
}

func swarm() {
    var particles: [Double] = Array(repeating: Double.random(in: 0...1), count: 10)
    var velocities: [Double] = Array(repeating: Double.random(in: 0...1), count: 10)
    var bestPositions: [Double] = particles
    var globalBest = particles.min() ?? 0
    let w: Double = 0.7
    let c1: Double = 1.5
    let c2: Double = 1.5
    while true {
        let result = optimize(particles: particles, velocities: velocities, bestPositions: bestPositions, globalBest: globalBest, w: w, c1: c1, c2: c2)
        particles = result.0
        velocities = result.1
        bestPositions = result.2
        globalBest = bestPositions.min() ?? 0
    }
}

swarm()