class Vectorizer {
    var data: [String]
    var index: Int

    init(data: [String]) {
        self.data = data
        self.index = 0
    }

    func process() -> AnyIterator<String> {
        return AnyIterator {
            if self.index < self.data.count {
                let item = self.data[self.index]
                self.index += 1
                return item
            } else {
                self.index = 0
                return nil
            }
        }
    }
}

class SequenceProcessor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func transform() -> AnyIterator<[Int]> {
        return AnyIterator {
            if let item = self.vectorizer.process().next() {
                return self.apply_transformation(item: item)
            } else {
                return nil
            }
        }
    }

    func apply_transformation(item: String) -> [Int] {
        return item.map { Int($0.asciiValue ?? 0) }
    }
}

class OutputHandler {
    var processor: SequenceProcessor

    init(processor: SequenceProcessor) {
        self.processor = processor
    }

    func display() {
        for vector in self.processor.transform() {
            print(vector)
        }
    }
}

func main() {
    let data = ["hello", "world", "this", "is", "a", "test", "sequence"]
    let vectorizer = Vectorizer(data: data)
    let processor = SequenceProcessor(vectorizer: vectorizer)
    let handler = OutputHandler(processor: processor)
    handler.display()
}

main()