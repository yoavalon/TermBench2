func processState(_ state: Int, _ data: String) -> String {
    if state == 0 {
        return processState(1, data + "a")
    } else if state == 1 {
        return processState(2, data + "b")
    } else if state == 2 {
        return processState(3, data + "c")
    } else if state == 3 {
        return data
    }
    return ""
}

func main() {
    let result = processState(0, "")
    print(result)
}

main()