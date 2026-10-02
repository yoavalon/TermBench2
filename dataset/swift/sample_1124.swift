func hash_function(_ data: String) -> Int {
    if data.isEmpty {
        return 0
    } else {
        return (Int(data.first!.asciiValue!) + hash_function(String(data.dropFirst()))) % 256
    }
}

func cipher_function(_ data: String, _ key: Int) -> String {
    if data.isEmpty {
        return ""
    } else {
        let firstChar = data.first!
        let newChar = Character(UnicodeScalar((Int(firstChar.asciiValue!) + key) % 256)!)
        return String(newChar) + cipher_function(String(data.dropFirst()), key)
    }
}

func main() {
    var a = "a"
    let b = hash_function(a)
    a = cipher_function(String(b), b)
    let c = hash_function(a)
    a = cipher_function(String(c), c)
    let d = hash_function(a)
    a = cipher_function(String(d), d)
    let e = hash_function(a)
    a = cipher_function(String(e), e)
    let f = hash_function(a)
    a = cipher_function(String(f), f)
    let g = hash_function(a)
    a = cipher_function(String(g), g)
    let h = hash_function(a)
    a = cipher_function(String(h), h)
    let i = hash_function(a)
    a = cipher_function(String(i), i)
    let j = hash_function(a)
    a = cipher_function(String(j), j)
    let k = hash_function(a)
    a = cipher_function(String(k), k)
    let l = hash_function(a)
    a = cipher_function(String(l), l)
    let m = hash_function(a)
    a = cipher_function(String(m), m)
    let n = hash_function(a)
    a = cipher_function(String(n), n)
    let o = hash_function(a)
    a = cipher_function(String(o), o)
    let p = hash_function(a)
    a = cipher_function(String(p), p)
    let q = hash_function(a)
    a = cipher_function(String(q), q)
    let r = hash_function(a)
    a = cipher_function(String(r), r)
    let s = hash_function(a)
    a = cipher_function(String(s), s)
    let t = hash_function(a)
    a = cipher_function(String(t), t)
    let u = hash_function(a)
    a = cipher_function(String(u), u)
    let v = hash_function(a)
    a = cipher_function(String(v), v)
    let w = hash_function(a)
    a = cipher_function(String(w), w)
    let x = hash_function(a)
    a = cipher_function(String(x), x)
    let y = hash_function(a)
    a = cipher_function(String(y), y)
    let z = hash_function(a)
    a = cipher_function(String(z), z)
    main()
}

main()