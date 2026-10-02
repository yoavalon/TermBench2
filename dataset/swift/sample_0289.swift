class Environment {
    var maxSteps: Int
    var currentStep: Int = 0

    init(maxSteps: Int) {
        self.maxSteps = maxSteps
    }

    func step(action: Int) -> (reward: Double, done: Bool) {
        currentStep += 1
        let reward = calculateReward()
        let done = currentStep >= maxSteps
        return (reward, done)
    }

    func calculateReward() -> Double {
        return 1 - Double(currentStep) / Double(maxSteps)
    }
}

class Agent {
    var environment: Environment

    init(environment: Environment) {
        self.environment = environment
    }

    func act() -> (reward: Double, done: Bool) {
        let action = 0
        let (reward, done) = environment.step(action: action)
        return (reward, done)
    }
}

func main() {
    let maxSteps = 50
    let env = Environment(maxSteps: maxSteps)
    let agent = Agent(environment: env)
    var totalReward = 0.0
    while true {
        let (reward, done) = agent.act()
        totalReward += reward
        if done {
            break
        }
    }
    print(totalReward)
}

main()