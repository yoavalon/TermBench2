import Foundation

func analyzeText(data: String) {
    let tokens = data.split(separator: " ")
    while true {
        print(tokens.joined(separator: " "))
    }
}

func main() {
    let text = "Floating point precision is crucial in scientific computations."
    analyzeText(data: text)
}

main()