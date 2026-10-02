import Foundation

class Environment {
    var state: Int
    let maxSteps: Int
    var currentStep: Int

    init() {
        state = 0
        maxSteps = 100
        currentStep = 0
    }

    func reset() -> Int {
        state = 0
        currentStep = 0
        return state
    }

    func step(action: Int) -> (Int, Int, Bool) {
        currentStep += 1
        let done = currentStep >= maxSteps
        let reward = calculateReward(action: action)
        state = updateState(action: action)
        return (state, reward, done)
    }

    func calculateReward(action: Int) -> Int {
        return action == 0 ? -1 : 1
    }

    func updateState(action: Int) -> Int {
        return state + action
    }
}

class Agent {
    var policy: [Double]

    init() {
        policy = [0.5, 0.5]
    }

    func selectAction() -> Int {
        let randomNumber = Double.random(in: 0...1)
        return randomNumber < policy[0] ? 0 : 1
    }
}

func main() {
    let env = Environment()
    let agent = Agent()
    let totalEpisodes = 10
    for episode in 0..<totalEpisodes {
        let state = env.reset()
        var done = false
        while !done {
            let action = agent.selectAction()
            let (newState, reward, isDone) = env.step(action: action)
            state = newState
            done = isDone
        }
        print("Episode \(episode + 1) completed")
    }
}

main()