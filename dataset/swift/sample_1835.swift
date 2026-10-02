import Foundation

func f(a: Double, b: Double) -> Double {
    if b == 0 {
        return Double.infinity
    } else {
        return a / b
    }
}

func main() {
    let result = f(a: 1.0, b: 2.0)
    print(result)
}

main()