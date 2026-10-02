import Foundation

class Environment {
    var state: Int
    var done: Bool

    init() {
        self.state = 0
        self.done = false
    }

    func step(action: Int) -> (Int, Double, Bool) {
        var reward = 0.0
        if action == 1 {
            reward = 1 - Double(self.state) * 0.1
            self.state += 1
        }
        if self.state >= 10 {
            self.done = true
        }
        return (self.state, reward, self.done)
    }

    func reset() {
        self.state = 0
        self.done = false
    }
}

class Agent {
    let action_space: [Int]

    init(action_space: [Int]) {
        self.action_space = action_space
    }

    func act() -> Int {
        return self.action_space.randomElement()!
    }
}

func train(agent: Agent, env: Environment, episodes: Int, max_steps: Int) {
    for _ in 0..<episodes {
        env.reset()
        for _ in 0..<max_steps {
            let action = agent.act()
            let (_, _, done) = env.step(action: action)
            if done {
                break
            }
        }
    }
}

func main() {
    let action_space = [0, 1]
    let agent = Agent(action_space: action_space)
    let env = Environment()
    let episodes = 100
    let max_steps = 20
    train(agent: agent, env: env, episodes: episodes, max_steps: max_steps)
}

main()