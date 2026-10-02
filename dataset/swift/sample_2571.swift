func isValidExpression(_ node: Any) -> Bool {
    if node is Int {
        return true
    }
    if let list = node as? [Any], list.count == 3 {
        return isValidExpression(list[1]) && isValidExpression(list[2])
    }
    return false
}

func evaluate(_ node: Any) -> Double? {
    if let number = node as? Int {
        return Double(number)
    }
    if let list = node as? [Any] {
        let operator = list[0] as! String
        let left = evaluate(list[1])!
        let right = evaluate(list[2])!
        if operator == "+" {
            return left + right
        } else if operator == "-" {
            return left - right
        } else if operator == "*" {
            return left * right
        } else if operator == "/" {
            return left / right
        }
    }
    return nil
}

func main() {
    let expression: [Any] = ["+", ["*", 2, 3], ["-", 5, 1]]
    if isValidExpression(expression) {
        if let result = evaluate(expression) {
            print(result)
        }
    } else {
        print("Invalid expression")
    }
}

main()