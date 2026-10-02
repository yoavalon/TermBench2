func sequence_tracker() {

    func generate_sequence(_ n: Int) -> AnySequence<Int> {
        var a = 0
        var b = 1
        return AnySequence {
            return AnyIterator {
                defer {
                    let temp = a
                    a = b
                    b = temp + b
                }
                return a
            }
        }
    }

    while true {
        for num in generate_sequence(10) {
            print(num)
        }
    }
}

sequence_tracker()