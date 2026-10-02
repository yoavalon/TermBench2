func main() {
    let gamma = 0.99
    let rewards = [100, 50, 25, 10, 5]
    var stateValue = 0.0
    for r in rewards {
        stateValue = gamma * stateValue + Double(r)
    }
    print(stateValue)
}

main()