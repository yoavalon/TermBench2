import Foundation

func main() {
    var reward = 1.0
    let decayRate = 0.95
    let threshold = 0.01
    var steps = 0
    while reward > threshold {
        reward *= decayRate
        steps += 1
    }
    print(steps)
}

main()