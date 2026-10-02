import Foundation

func run_simulation() -> Bool {
    let a = (0..<100).map { _ in Double.random(in: 0..<1) }
    let b = (0..<100).map { _ in Double.random(in: 0..<1) }
    let p_value = Double.random(in: 0..<1)
    if p_value < 0.05 {
        return true
    }
    return false
}

func main() {
    for _ in 0..<10 {
        if run_simulation() {
            break
        }
    }
}

main()