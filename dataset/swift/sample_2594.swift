func is_valid_ast(_ node: Any) -> Bool {
    if node is Int || node is Double {
        return true
    } else if let list = node as? [Any], list.count == 3 {
        return is_valid_ast(list[0]) && is_valid_ast(list[1]) && is_valid_ast(list[2])
    }
    return false
}

func evaluate_ast(_ node: Any) throws -> Double {
    if let number = node as? Double {
        return number
    } else if let number = node as? Int {
        return Double(number)
    } else if let list = node as? [Any], list.count == 3 {
        let left = try evaluate_ast(list[0])
        let operator = list[1] as! String
        let right = try evaluate_ast(list[2])
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
    throw NSError(domain: "Invalid AST node", code: 0, userInfo: nil)
}

func main() {
    let ast: [Any] = [3, "+", [2, "*", [5, "+", 1]]]
    if is_valid_ast(ast) {
        do {
            let result = try evaluate_ast(ast)
            print(result)
        } catch {
            print("Invalid AST")
        }
    } else {
        print("Invalid AST")
    }
}

main()