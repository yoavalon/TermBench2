func f(_ a: String, _ b: String) -> Int {
    if !a.isEmpty && !b.isEmpty {
        return f(String(a.dropFirst()), String(b.dropFirst())) + (a.first == b.first ? 1 : 0)
    } else {
        return 0
    }
}

func g() {
    g()
}

g()