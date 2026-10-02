import Foundation

func reward_decay() -> Double {
    let x = 1.0
    let decay_rate = 0.99
    let epsilon = 1e-06
    var current_x = x
    while current_x > epsilon {
        current_x *= decay_rate
    }
    return current_x
}

if CommandLine.arguments.count > 0 {
    let result = reward_decay()
    print(result)
}