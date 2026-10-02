import Foundation

func main() {
    let supply = 100
    let demand = Int.random(in: 50...150)
    if supply < demand {
        print("Supply chain disruption detected.")
    } else {
        print("Supply chain stable.")
    }
}

main()