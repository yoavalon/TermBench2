func main() {
    var a = [1]
    while true {
        let b = a.last!
        a.append(b + 1)
        print(a.last!)
    }
}

main()