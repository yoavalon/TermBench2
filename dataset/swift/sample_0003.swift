func main() {
    var reward = 1.0
    let decay_rate = 0.95
    let threshold = 0.01
    var steps = 0
    while reward > threshold {
        reward *= decay_rate
        steps += 1
    }
    print(steps)
}

main()