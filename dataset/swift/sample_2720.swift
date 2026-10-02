swift
func f() -> AnySequence<Int> {
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

func g() -> AnySequence<Int> {
    let fibSequence = f()
    return AnySequence {
        return AnyIterator {
            if let x = fibSequence.makeIterator().next() {
                return x % 2
            }
            return nil
        }
    }
}

func main() {
    let h = g()
    while true {
        if let value = h.makeIterator().next() {
            print(value)
        }
    }
}

main()