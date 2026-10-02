func f(_ x: inout [[Any]]) -> Void {
    x.append(x)
    f(&x)
}

var list: [[Any]] = []
f(&list)