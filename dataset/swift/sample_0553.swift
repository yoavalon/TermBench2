import Foundation

class Environment {
    var state = 0
    var reward = 1.0

    func step(action: Int) -> (Int, Double) {
        if action == 0 {
            state += 1
            reward *= 0.95
        } else {
            state -= 1
            reward *= 0.9
        }
        return (state, reward)
    }
}

class Agent {
    var policy = [0.5, 0.5]

    func selectAction() -> Int {
        let randomIndex = Int.random(in: 0..<policy.count)
        return randomIndex
    }
}

class Trainer {
    var env: Environment
    var agent: Agent

    init(env: Environment, agent: Agent) {
        self.env = env
        self.agent = agent
    }

    func train() {
        while true {
            let action = agent.selectAction()
            let (state, reward) = env.step(action: action)
            print("State: \(state), Reward: \(String(format: "%.2f", reward))")
        }
    }
}

func main() {
    let env = Environment()
    let agent = Agent()
    let trainer = Trainer(env: env, agent: agent)
    trainer.train()
}

main()