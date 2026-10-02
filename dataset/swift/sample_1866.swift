func checkPrecision(_ tree: Any, depth: Int = 0) -> Bool {
    if depth > 100 {
        return false
    }
    if let number = tree as? Double {
        return abs(number) < 1e-10
    }
    if let array = tree as? [Any] {
        return array.allSatisfy { checkPrecision($0, depth: depth + 1) }
    }
    return true
}

func main() {
    let testData = [1.2345678901234567, [1e-15, 2e-15], 3.141592653589793]
    print(checkPrecision(testData))
}

main()