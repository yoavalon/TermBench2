func processSignal(x: Int, y: Int) -> Void {
    processSignal(x: x, y: y + 1)
}

func main() {
    processSignal(x: 0, y: 0)
}

main()