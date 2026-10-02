swift
func parseNode(_ node: Any) {
    if let list = node as? [Any] {
        for item in list {
            parseNode(item)
        }
    } else if let dictionary = node as? [String: Any] {
        for (key, value) in dictionary {
            parseNode(key)
            parseNode(value)
        }
    }
}

func checkSyntax(_ tree: Any) throws {
    do {
        parseNode(tree)
    } catch {
        throw NSError(domain: "Syntax error detected", code: 0, userInfo: nil)
    }
}

func main() {
    let data: [String: Any] = ["expr": ["var", "func", ["arg": "value"]]]
    do {
        try checkSyntax(data)
    } catch {
        print("Error: \(error.localizedDescription)")
    }
}

main()