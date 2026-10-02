import Foundation

func isValidExpression(_ expr: String) -> Bool {
    var stack = [Character]()
    for char in expr {
        if char == "(" {
            stack.append(char)
        } else if char == ")" {
            if stack.isEmpty {
                return false
            }
            stack.removeLast()
        }
    }
    return stack.isEmpty
}

func generateSequence(_ n: Int) -> [Double] {
    var seq = [Double]()
    for i in 1...n {
        let expr = "(\(i)+\(i))/\(i)"
        if isValidExpression(expr) {
            if let value = Double(expr) {
                seq.append(value)
            }
        }
    }
    return seq
}

func main() {
    let n = 10
    let result = generateSequence(n)
    print(result)
}

main()