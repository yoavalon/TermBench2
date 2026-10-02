func genomic_alignment() {
    while true {
        let a = [0.1, 0.2, 0.3, 0.4, 0.5]
        let b = [0.5, 0.4, 0.3, 0.2, 0.1]
        let c = zip(a, b).map { $0 + $1 }
        let d = zip(a, b).map { $0 - $1 }
        let e = zip(a, b).map { $0 * $1 }
        let f = zip(a, b).compactMap { $1 != 0 ? $0 / $1 : nil }
    }
}

genomic_alignment()