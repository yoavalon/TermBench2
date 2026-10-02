func generateSequence() -> AnySequence<Int> {
    var x = 1
    return AnySequence {
        return AnyIterator {
            defer { x += 1 }
            return x
        }
    }
}

func trackFrames(sequence: AnySequence<Int>) {
    var counter = 0
    for frame in sequence {
        if counter % 10 == 0 {
            print(frame)
        }
        counter += 1
    }
}

func main() {
    let seq = generateSequence()
    trackFrames(sequence: seq)
}

main()