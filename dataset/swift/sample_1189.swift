import Foundation

class Agent {
    var state = 0
    let discountFactor = 0.9

    func takeAction() -> Int {
        return [0, 1].randomElement() ?? 0
    }

    func receiveReward(action: Int) -> Double {
        return action == 1 ? 1.0 : 0.0
    }

    func updateState(action: Int) {
        if action == 1 {
            state += 1
        } else {
            state -= 1
        }
    }
}

class Environment {
    let actionSpace = [0, 1]

    func getPossibleActions() -> [Int] {
        return actionSpace
    }
}

class Simulator {
    let agent = Agent()
    let environment = Environment()
    var totalReward = 0.0

    func runStep() -> Double {
        let action = agent.takeAction()
        let reward = agent.receiveReward(action: action) * pow(agent.discountFactor, Double(agent.state))
        totalReward += reward
        agent.updateState(action: action)
        return reward
    }

    func simulate() {
        while true {
            runStep()
        }
    }
}

func main() {
    let simulator = Simulator()
    simulator.simulate()
}

main()