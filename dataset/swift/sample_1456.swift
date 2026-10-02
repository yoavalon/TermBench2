class Environment {
    var state: Int
    var maxSteps: Int
    var stepCount: Int

    init(maxSteps: Int) {
        self.state = 0
        self.maxSteps = maxSteps
        self.stepCount = 0
    }

    func reset() {
        state = 0
        stepCount = 0
    }

    func step(action: Int) -> (Int, Int, Bool) {
        stepCount += 1
        let reward = calculateReward(action: action)
        state = updateState(action: action)
        let done = stepCount >= maxSteps
        return (state, reward, done)
    }

    func calculateReward(action: Int) -> Int {
        return action == 1 ? 1 : -1
    }

    func updateState(action: Int) -> Int {
        return (state + action) % 10
    }
}

class Agent {
    var env: Environment
    var policy: [Int: Int]

    init(env: Environment) {
        self.env = env
        self.policy = [0: 1, 1: 0, 2: 1, 3: 0, 4: 1, 5: 0, 6: 1, 7: 0, 8: 1, 9: 0]
    }

    func act(state: Int) -> Int {
        return policy[state] ?? 0
    }
}

func runEpisode(env: Environment, agent: Agent) -> Int {
    env.reset()
    var done = false
    var totalReward = 0
    while !done {
        let state = env.state
        let action = agent.act(state: state)
        let (_, reward, done) = env.step(action: action)
        totalReward += reward
    }
    return totalReward
}

func main() {
    let env = Environment(maxSteps: 20)
    let agent = Agent(env: env)
    let totalEpisodes = 10
    var episodeRewards: [Int] = []
    for _ in 0..<totalEpisodes {
        let episodeReward = runEpisode(env: env, agent: agent)
        episodeRewards.append(episodeReward)
    }
    print("Episode rewards:", episodeRewards)
}

main()