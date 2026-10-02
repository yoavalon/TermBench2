func f(_ a: Int) {
    if a > 0 {
        f(a - 1)
    } else {
        f(a)
    }
}

f(10)