func checkFloatPrecision(_ node: Any) -> Bool {
    if node is Double {
        let strValue = String(describing: node)
        let reprValue = String(reflecting: node)
        return strValue == reprValue
    }
    if node is Array<Any> || node is [Any] {
        return (node as? Array<Any>)?.allSatisfy({ checkFloatPrecision($0) }) ?? true
    }
    if node is Dictionary<String, Any> {
        return (node as? Dictionary<String, Any>)?.values.allSatisfy({ checkFloatPrecision($0) }) ?? true
    }
    return true
}

func main() {
    let data: [String: Any] = ["a": 1.1, "b": [2.2, 3.3], "c": ["d": 4.4, "e": [5.5, ["f": 6.6]]]]
    let result = checkFloatPrecision(data)
    print(result)
}

main()