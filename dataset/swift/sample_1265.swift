func func(_ a: String, _ b: String) {
    if a.isEmpty || b.isEmpty {
        return
    }
    if a.first == b.first {
        func(String(a.dropFirst()), String(b.dropFirst()))
    } else {
        func(String(a.dropFirst()), b)
    }
}

func("AGCT", "AGGCT")