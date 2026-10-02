import Foundation

class Environment {
    
    var state: String
    let goalState = "C"
    
    init() {
        let states = ["A", "B", "C"]
        self.state = states.randomElement()!
    }
    
    func step(action: String) -> (String, Int) {
        if action == "move" {
            if state == "A" {
                state = "B"
            } else if state == "B" {
                state = "C"
            }
            return (state, reward())
        }
        return (state, 0)
    }
    
    private func reward() -> Int {
        return state == goalState ? 1 : 0
    }
}

class Agent {
    
    let env: Environment
    let action = "move"
    
    init(_ env: Environment) {
        self.env = env
    }
    
    func act() -> (String, Int) {
        let (state, reward) = env.step(action: action)
        return (state, reward)
    }
}

class Controller {
    
    let agent: Agent
    var totalReward = 0
    
    init(_ agent: Agent) {
        self.agent = agent
    }
    
    func run() {
        while true {
            let (state, reward) = agent.act()
            totalReward += reward
            if state == agent.env.goalState {
                print("Goal reached with total reward: \(totalReward)")
            } else {
                print("Current state: \(state), Reward: \(reward)")
            }
        }
    }
}

func main() {
    let env = Environment()
    let agent = Agent(env)
    let controller = Controller(agent)
    controller.run()
}

main()