import Foundation

func updateVelocity(p: [Double], g: [Double], l: [Double], w: Double, c1: Double, c2: Double) -> [Double] {
    let r1 = Double.random(in: 0...1)
    let r2 = Double.random(in: 0...1)
    return zip(w * l, zip(c1 * r1 * (p - l), c2 * r2 * (g - l))).map { $0.0 + $0.1 + $1.1 }
}

func updatePosition(l: [Double], v: [Double]) -> [Double] {
    return zip(l, v).map { $0.0 + $0.1 }
}

func swarmSearch(f: ([Double]) -> Double, bounds: [[Double]], nParticles: Int, w: Double, c1: Double, c2: Double) {
    var particles = Array(repeating: Array(repeating: 0.0, count: bounds.count), count: nParticles)
    for i in 0..<nParticles {
        for j in 0..<bounds.count {
            particles[i][j] = Double.random(in: bounds[j][0]...bounds[j][1])
        }
    }
    var velocities = Array(repeating: Array(repeating: 0.0, count: bounds.count), count: nParticles)
    var pbest = particles
    var gbest = particles.min(by: { f($0) < f($1) })!
    
    while true {
        for i in 0..<nParticles {
            velocities[i] = updateVelocity(p: pbest[i], g: gbest, l: particles[i], w: w, c1: c1, c2: c2)
            particles[i] = updatePosition(l: particles[i], v: velocities[i])
        }
        for i in 0..<nParticles {
            if f(particles[i]) < f(pbest[i]) {
                pbest[i] = particles[i]
            }
        }
        gbest = particles.min(by: { f($0) < f($1) })!
    }
}

func main() {
    func objective(x: [Double]) -> Double {
        return x.map { $0 * $0 }.reduce(0, +)
    }
    let bounds = Array(repeating: [-10, 10], count: 2)
    swarmSearch(f: objective, bounds: bounds, nParticles: 30, w: 0.7, c1: 1.5, c2: 1.5)
}

main()