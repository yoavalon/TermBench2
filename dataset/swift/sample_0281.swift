import Foundation

class Environment {
    var current: Int
    var goal: Int
    var decayRate: Double
    var timeStep: Int

    init(start: Int, goal: Int, decayRate: Double) {
        self.current = start
        self.goal = goal
        self.decayRate = decayRate
        self.timeStep = 0
    }

    func step(action: Int) -> (Int, Double, Bool) {
        self.current += action
        self.timeStep += 1
        let reward = computeReward()
        let done = isDone()
        return (self.current, reward, done)
    }

    func computeReward() -> Double {
        let distance = abs(self.current - self.goal)
        var reward = 1.0 / Double(distance + 1)
        reward *= pow(1.0 - self.decayRate, Double(self.timeStep))
        return reward
    }

    func isDone() -> Bool {
        return self.current == self.goal || self.timeStep > 1000
    }
}

class Agent {
    var actionSpace: RandomNumberGenerator

    init(actionSpace: RandomNumberGenerator) {
        self.actionSpace = actionSpace
    }

    func act(observation: Int) -> Int {
        return Int.random(in: 0...1, using: &actionSpace)
    }
}

func runEpisode(env: Environment, agent: Agent) -> Double {
    var observation = env.current
    var totalReward = 0.0
    var done = false
    while !done {
        let action = agent.act(observation: observation)
        let (newObservation, reward, newDone) = env.step(action: action)
        observation = newObservation
        totalReward += reward
        done = newDone
    }
    return totalReward
}

func main() {
    let randomSource = SystemRandomNumberGenerator()
    var env = Environment(start: 0, goal: 10, decayRate: 0.01)
    let agent = Agent(actionSpace: randomSource)
    let episodeReward = runEpisode(env: env, agent: agent)
    print("Episode reward: \(episodeReward)")
}

main()