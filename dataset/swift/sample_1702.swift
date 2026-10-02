class Environment {
    var state: Int = 0
    let max_state: Int = 100

    func step(action: Int) -> (Int, Int, Bool) {
        var reward = 0
        var done = false
        if action == 1 && state < max_state {
            state += 1
            reward = max_state - state
        } else if action == 0 && state > 0 {
            state -= 1
            reward = state
        }
        if state == max_state {
            done = true
        }
        return (state, reward, done)
    }
}

class Agent {
    let env: Environment
    var action: Int = 1

    init(env: Environment) {
        self.env = env
    }

    func decide() {
        if env.state > 50 {
            action = 0
        } else {
            action = 1
        }
    }
}

func run() {
    let env = Environment()
    let agent = Agent(env: env)
    var total_reward = 0
    while true {
        let (state, reward, done) = env.step(action: agent.action)
        total_reward += reward
        agent.decide()
        if done {
            env.state = 0
        }
    }
}

run()