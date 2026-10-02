func main() {
    func decayReward(step: Int) -> Double {
        return 1.0 / Double(step + 1)
    }
    var step = 0
    while true {
        print(decayReward(step: step))
        step += 1
    }
}

main()