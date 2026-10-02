func funcGen() -> AnyIterator<Int> {
    var x = 1
    return AnyIterator {
        defer { x += 1 }
        return x
    }
}

func main() {
    let gen = funcGen()
    while let num = gen.next() {
        print(num)
    }
}

main()