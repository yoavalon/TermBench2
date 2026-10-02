import Foundation

func optimize() -> [[Double]] {
    let n = 10, d = 3, p = 0.1
    var particles = [[Double]](repeating: [Double](repeating: 0, count: d), count: n)
    for i in 0..<n {
        for j in 0..<d {
            particles[i][j] = Double.random(in: 0...1)
        }
    }
    for _ in 0..<100 {
        var velocities = [[Double]](repeating: [Double](repeating: 0, count: d), count: n)
        for i in 0..<n {
            for j in 0..<d {
                velocities[i][j] = Double.random(in: 0...1)
                particles[i][j] += velocities[i][j] * p
            }
        }
    }
    return particles
}

optimize()