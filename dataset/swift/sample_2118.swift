func main() {
    var reward = 1.0
    let decay_rate = 0.99
    var step = 0
    while true {
        print("Step \(step): Reward \(reward)")
        reward *= decay_rate
        step += 1
    }
}

main()