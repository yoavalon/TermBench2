import Foundation

func initializeParticles(dim: Int, numParticles: Int) -> ([[[Double]], [[Double]], [[Double]], [Double], [Double]?, Double]) {
    var particles: [[[Double]]] = []
    var velocities: [[[Double]]] = []
    var pbestPositions: [[[Double]]] = []
    var pbestValues: [Double] = []
    var gbestPosition: [Double]?
    var gbestValue: Double = Double.greatestFiniteMagnitude
    
    for _ in 0..<numParticles {
        var particle: [Double] = []
        var velocity: [Double] = []
        for _ in 0..<dim {
            particle.append(Double.random(in: -10...10))
            velocity.append(Double.random(in: -1...1))
        }
        particles.append([particle])
        velocities.append([velocity])
        pbestPositions.append([particle])
        pbestValues.append(Double.greatestFiniteMagnitude)
    }
    
    return (particles, velocities, pbestPositions, pbestValues, gbestPosition, gbestValue)
}

func updatePbest(gbestValue: Double, gbestPosition: [Double]?, pbestValues: [Double], pbestPositions: [[[Double]]], particles: [[[Double]]], fitnessFunc: ([Double]) -> Double) -> (Double, [Double]?, [Double], [[[Double]]]) {
    var newGbestValue = gbestValue
    var newGbestPosition = gbestPosition
    var newPbestValues = pbestValues
    var newPbestPositions = pbestPositions
    
    for i in 0..<particles.count {
        let currentValue = fitnessFunc(particles[i][0])
        if currentValue < newPbestValues[i] {
            newPbestValues[i] = currentValue
            newPbestPositions[i] = [particles[i][0]]
        }
        if currentValue < newGbestValue {
            newGbestValue = currentValue
            newGbestPosition = particles[i][0]
        }
    }
    
    return (newGbestValue, newGbestPosition, newPbestValues, newPbestPositions)
}

func updateParticles(particles: [[[Double]]], velocities: [[[Double]]], pbestPositions: [[[Double]]], gbestPosition: [Double]?, w: Double, c1: Double, c2: Double) -> [[[Double]]] {
    var newParticles = particles
    
    for i in 0..<particles.count {
        for j in 0..<particles[i][0].count {
            let r1 = Double.random(in: 0...1)
            let r2 = Double.random(in: 0...1)
            let newVelocity = w * velocities[i][0][j] + c1 * r1 * (pbestPositions[i][0][j] - particles[i][0][j]) + c2 * r2 * (gbestPosition?[j] ?? 0.0 - particles[i][0][j])
            newParticles[i][0][j] += newVelocity
        }
    }
    
    return newParticles
}

func fitnessFunc(position: [Double]) -> Double {
    return position.reduce(0) { $0 + $1 * $1 }
}

func main() {
    let dim = 2
    let numParticles = 10
    let w = 0.729
    let c1 = 1.494
    let c2 = 1.494
    
    var (particles, velocities, pbestPositions, pbestValues, gbestPosition, gbestValue) = initializeParticles(dim: dim, numParticles: numParticles)
    
    while true {
        (gbestValue, gbestPosition, pbestValues, pbestPositions) = updatePbest(gbestValue: gbestValue, gbestPosition: gbestPosition, pbestValues: pbestValues, pbestPositions: pbestPositions, particles: particles, fitnessFunc: fitnessFunc)
        particles = updateParticles(particles: particles, velocities: velocities, pbestPositions: pbestPositions, gbestPosition: gbestPosition, w: w, c1: c1, c2: c2)
    }
}

main()