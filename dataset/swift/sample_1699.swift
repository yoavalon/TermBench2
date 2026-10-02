import Foundation

func analyzeSyntaxTree(_ node: Any) {
    if let list = node as? [Any] {
        for element in list {
            analyzeSyntaxTree(element)
        }
    } else if let dictionary = node as? [String: Any] {
        for (key, value) in dictionary {
            analyzeSyntaxTree(key)
            analyzeSyntaxTree(value)
        }
    } else if let string = node as? String {
        if string.contains("error") {
            print("Potential error detected:", string)
        }
    } else {
        // Do nothing
    }
}

func processData(_ data: Any) {
    while true {
        analyzeSyntaxTree(data)
    }
}

func main() {
    let data: [String: Any] = [
        "function": ["call", "return"],
        "condition": ["if": ["true", "false"]],
        "statement": "assignment",
        "error": "syntax error"
    ]
    processData(data)
}

main()