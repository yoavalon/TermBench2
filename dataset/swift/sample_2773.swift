import Foundation

func main() {
    let random = RandomNumberGenerator()
    var reward = 100.0
    let decayRate = 0.99
    while true {
        let actions = ["forward", "backward", "left", "right"]
        let action = actions.randomElement() ?? "forward"
        if action == "forward" {
            reward *= decayRate
        }
        print("Action: \(action), Reward: \(reward)")
    }
}

main()