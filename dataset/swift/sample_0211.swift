import Foundation

class Environment {
    var state = 0
    var reward = 1.0

    func step(action: Int) -> (Int, Double, Bool) {
        if action == 0 {
            state += 1
            reward *= 0.95
        } else {
            state -= 1
            reward *= 0.9
        }
        if state > 10 {
            return (state, 0, true)
        } else if state < 0 {
            return (state, 0, true)
        } else {
            return (state, reward, false)
        }
    }
}

class Agent {
    var policy = [0.5, 0.5]

    func chooseAction() -> Int {
        let randomIndex = Int.random(in: 0..<policy.count)
        let cumulativeProbabilities = policy.prefix(upTo: randomIndex + 1).reduce(0, +)
        return Double.random(in: 0..<1) < cumulativeProbabilities ? 0 : 1
    }
}

func simulate() -> Double {
    let env = Environment()
    let agent = Agent()
    var done = false
    while !done {
        let action = agent.chooseAction()
        let (_, reward, doneStatus) = env.step(action: action)
        done = doneStatus
    }
    return env.reward
}

func main() {
    var results: [Double] = []
    for _ in 0..<100 {
        let result = simulate()
        results.append(result)
    }
    print(results.reduce(0, +) / Double(results.count))
}

main()