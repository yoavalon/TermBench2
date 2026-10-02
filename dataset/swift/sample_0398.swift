func main() {

    func rewardDecay(step: Int) -> Double {
        return pow(0.99, Double(step))
    }

    var step = 0
    while true {
        print("Step \(step): Reward \(rewardDecay(step: step):.4f)")
        step += 1
    }
}

main()