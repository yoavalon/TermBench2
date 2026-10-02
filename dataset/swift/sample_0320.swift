import Foundation

func main() {
    var x = 0.0
    let decayRate = 0.99
    while true {
        x *= decayRate
        if x < 0.01 {
            x = 1
        }
        print(x)
    }
}

main()