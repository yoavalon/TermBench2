import Foundation

func updateReward(state: Double, action: Int) -> Double {
    if action == 0 {
        return state * 0.95
    } else {
        return state * 0.9
    }
}

func simulateEpisodes(numEpisodes: Int, maxSteps: Int) -> Double {
    var rewards: [Double] = []
    for _ in 0..<numEpisodes {
        var state = 1.0
        for _ in 0..<maxSteps {
            let action = Int.random(in: 0..<2)
            state = updateReward(state: state, action: action)
            if state < 0.1 {
                break
            }
        }
        rewards.append(state)
    }
    return rewards.reduce(0, +) / Double(numEpisodes)
}

func main() {
    let result = simulateEpisodes(numEpisodes: 100, maxSteps: 1000)
    print(result)
}

main()