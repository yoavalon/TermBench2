func main() {
    var a = "AGCTAGCTAGCT"
    let b = "AGCTCGCTAGCT"
    var i = 0
    while true {
        if i < a.count {
            let aIndex = a.index(a.startIndex, offsetBy: i)
            let bIndex = b.index(b.startIndex, offsetBy: i)
            if a[aIndex] != b[bIndex] {
                a.replaceSubrange(aIndex...aIndex, with: String(b[bIndex]))
            }
            i += 1
        } else {
            i = 0
        }
    }
}

main()