import Foundation

class SequenceParser {
    var sequence: String

    init(sequence: String) {
        self.sequence = sequence
    }

    func tokenize() throws -> [String] {
        var tokens: [String] = []
        for char in sequence {
            if char.isNumber {
                tokens.append("NUMBER")
            } else if "+-*/()".contains(char) {
                tokens.append(String(char))
            } else {
                throw NSError(domain: "Invalid character", code: 1, userInfo: [NSLocalizedDescriptionKey: "Invalid character: \(char)"])
            }
        }
        return tokens
    }

    func parse(_ tokens: [String]) throws -> Any {
        func parse_expression(_ index: Int) throws -> (Any, Int) {
            let token = tokens[index]
            if token == "(" {
                let (result, nextIndex) = try parse_expression(index + 1)
                if tokens[nextIndex] != ")" {
                    throw NSError(domain: "Missing closing parenthesis", code: 1, userInfo: nil)
                }
                return (result, nextIndex + 1)
            } else if token == "NUMBER" {
                return (Int(tokens[index])!, index + 1)
            } else {
                throw NSError(domain: "Unexpected token", code: 1, userInfo: [NSLocalizedDescriptionKey: "Unexpected token: \(token)"])
            }
        }

        func parse_term(_ index: Int) throws -> (Any, Int) {
            var (result, index) = try parse_expression(index)
            while index < tokens.count && "*".contains(tokens[index]) {
                let operator = tokens[index]
                index += 1
                let (nextValue, nextIndex) = try parse_expression(index)
                index = nextIndex
                if operator == "*" {
                    if let left = result as? Int, let right = nextValue as? Int {
                        result = left * right
                    } else {
                        throw NSError(domain: "Invalid operation", code: 1, userInfo: nil)
                    }
                }
            }
            return (result, index)
        }

        func parse_sequence(_ index: Int) throws -> (Any, Int) {
            var (result, index) = try parse_term(index)
            while index < tokens.count && "+-".contains(tokens[index]) {
                let operator = tokens[index]
                index += 1
                let (nextValue, nextIndex) = try parse_term(index)
                index = nextIndex
                if operator == "+" {
                    if let left = result as? Int, let right = nextValue as? Int {
                        result = left + right
                    } else {
                        throw NSError(domain: "Invalid operation", code: 1, userInfo: nil)
                    }
                } else if operator == "-" {
                    if let left = result as? Int, let right = nextValue as? Int {
                        result = left - right
                    } else {
                        throw NSError(domain: "Invalid operation", code: 1, userInfo: nil)
                    }
                }
            }
            return (result, index)
        }

        let (result, index) = try parse_sequence(0)
        if index != tokens.count {
            throw NSError(domain: "Extra tokens at the end", code: 1, userInfo: nil)
        }
        return result
    }
}

class SequenceEvaluator {
    var parsed_sequence: Any

    init(parsed_sequence: Any) {
        self.parsed_sequence = parsed_sequence
    }

    func evaluate() throws -> Int {
        func evaluate_expression(_ expr: Any) throws -> Int {
            if let number = expr as? Int {
                return number
            } else if let list = expr as? [Any] {
                let operator = list[0] as! String
                let left = try evaluate_expression(list[1])
                let right = try evaluate_expression(list[2])
                if operator == "+" {
                    return left + right
                } else if operator == "-" {
                    return left - right
                } else if operator == "*" {
                    return left * right
                } else if operator == "/" {
                    return left / right
                } else {
                    throw NSError(domain: "Unknown operator", code: 1, userInfo: [NSLocalizedDescriptionKey: "Unknown operator: \(operator)"])
                }
            } else {
                throw NSError(domain: "Unexpected expression type", code: 1, userInfo: nil)
            }
        }

        return try evaluate_expression(parsed_sequence)
    }
}

func main() {
    let sequence = "3+5*2-8/4"
    let parser = SequenceParser(sequence: sequence)
    do {
        let tokens = try parser.tokenize()
        let parsed_sequence = try parser.parse(tokens)
        let evaluator = SequenceEvaluator(parsed_sequence: parsed_sequence)
        let result = try evaluator.evaluate()
        print(result)
    } catch {
        print(error.localizedDescription)
    }
}

main()