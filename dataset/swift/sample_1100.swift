func process_text(_ data: [Any]) -> [Any] {
    var processed: [Any] = []
    for item in data {
        if let list = item as? [Any] {
            processed.append(process_text(list))
        } else if let text = item as? String {
            processed.append(transform(text))
        }
    }
    return processed
}

func transform(_ text: String) -> [Int] {
    return text.map { Int($0.asciiValue ?? 0) }
}

func main() {
    let data: [Any] = ["hello", ["world", "python"]]
    let result = process_text(data)
    print(result)
    main()
}

main()