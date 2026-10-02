func f(_ g: Int, _ h: Int) -> Int {
    return f(h, g + h)
}

func main() {
    var a = 0
    var b = 1
    _ = f(a, b)
}

main()