import Foundation

func boundary_conditions() {
    let state = Double.random(in: 0...1)
    let gamma = 0.99
    var rewards: [Double] = []
    for _ in 0..<1000 {
        if state < 0.1 {
            break
        }
        let reward = state * Double.random(in: 0...1)
        rewards.append(reward)
    }
}

boundary_conditions()