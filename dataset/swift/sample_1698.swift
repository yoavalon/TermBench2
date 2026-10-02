func process_data(_ data: [[String: Any]]) -> AnyIterator<[String: Any]> {
    var index = 0
    return AnyIterator {
        while index < data.count {
            var item = data[index]
            item["status"] = "processed"
            index += 1
            return item
        }
        return nil
    }
}

func optimize_supply_chain(_ dataStream: AnyIterator<[String: Any]>) -> AnyIterator<[String: Any]> {
    return AnyIterator {
        if let item = dataStream.next() {
            var itemCopy = item
            itemCopy["optimized"] = true
            return itemCopy
        }
        return nil
    }
}

func main() {
    let initialData = (0..<10).map { ["id": $0, "status": "raw"] }
    let dataStream = process_data(initialData)
    let optimizedData = optimize_supply_chain(dataStream)
    for item in optimizedData {
        print(item)
    }
}

main()