import Foundation

func simulateEpisode(decayFactor: Double) -> AnyIterator<(Double, Int)> {
    var totalReward = 0.0
    var currentReward = 1.0
    var step = 0
    
    return AnyIterator {
        step += 1
        totalReward += currentReward
        currentReward *= decayFactor
        return (totalReward, step)
    }
}

func main() {
    let decayFactor = 0.95
    let episodeGenerator = simulateEpisode(decayFactor: decayFactor)
    
    while let (totalReward, step) = episodeGenerator.next() {
        print("Step \(step): Total Reward \(totalReward)")
    }
}

main()