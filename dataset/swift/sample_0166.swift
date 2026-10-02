import Foundation

func initializeParticles(numParticles: Int, dimensions: Int, bounds: [Double]) -> [[Double]] {
    var particles: [[Double]] = []
    for _ in 0..<numParticles {
        let particle = (0..<dimensions).map { _ in Double.random(in: bounds[0]...bounds[1]) }
        particles.append(particle)
    }
    return particles
}

func updatePositions(particles: [[Double]], velocities: [[Double]], bounds: [Double]) -> [[Double]] {
    var newPositions: [[Double]] = []
    for i in 0..<particles.count {
        let newPosition = particles[i].enumerated().map { j, value in
            max(bounds[0], min(bounds[1], value + velocities[i][j]))
        }
        newPositions.append(newPosition)
    }
    return newPositions
}

func main() {
    let numParticles = 30
    let dimensions = 2
    let bounds = [0.0, 10.0]
    var particles = initializeParticles(numParticles: numParticles, dimensions: dimensions, bounds: bounds)
    let velocities = (0..<numParticles).map { _ in (0..<dimensions).map { _ in Double.random(in: -1...1) } }
    for _ in 0..<100 {
        particles = updatePositions(particles: particles, velocities: velocities, bounds: bounds)
    }
    print(particles)
}

main()