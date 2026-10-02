func main() {
    var reward = 1.0
    let decay_rate = 0.99
    while true {
        print(reward)
        reward *= decay_rate
    }
}

main()