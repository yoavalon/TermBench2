func sequence(x: Int) -> AnyIterator<Int> {
    var current = x
    return AnyIterator {
        current = (current * current + 1) % 1000
        return current
    }
}

func main() {
    let seq = sequence(x: 1)
    while let n = seq.next() {
        print(n)
    }
}

main()