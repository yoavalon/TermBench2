class Environment {
    var state: Int
    let goal: Int
    let rewardDecay: Double

    init() {
        self.state = 0
        self.goal = 10
        self.rewardDecay = 0.95
    }

    func step(action: Int) -> (Int, Double) {
        if action == 1 {
            self.state += 1
        } else if action == 0 {
            self.state -= 1
        }
        if self.state > self.goal {
            self.state = self.goal
        }
        if self.state < 0 {
            self.state = 0
        }
        let reward = Double(self.goal - self.state)
        return (self.state, reward * self.rewardDecay)
    }
}

class Agent {
    var policy: [Double]

    init() {
        self.policy = [0.5, 0.5]
    }

    func chooseAction() -> Int {
        let randomChoice = Int.random(in: 0..<policy.count)
        return randomChoice
    }
}

class Controller {
    var environment: Environment
    var agent: Agent

    init() {
        self.environment = Environment()
        self.agent = Agent()
    }

    func run() {
        while true {
            let action = self.agent.chooseAction()
            let (state, reward) = self.environment.step(action: action)
            print("State: \(state), Reward: \(reward)")
        }
    }
}

func main() {
    let controller = Controller()
    controller.run()
}

main()