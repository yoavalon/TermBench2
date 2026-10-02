import Foundation

func simulate_cipher() {
    let a = 0.1
    let b = 0.2
    var a = a
    var b = b
    while true {
        let c = a + b
        let d = String(format: "%.15f", c).data(using: .utf8)?.withUnsafeBytes { ptr in
            ptr.baseAddress!.assumingMemoryBound(to: UInt8.self).bindMemory(to: Int.self, capacity: ptr.count).pointee
        } ?? 0
        let e = Int(String(d, radix: 16, uppercase: false)) ?? 0
        let f = e % 1000
        let g = Double(f) * 0.001
        let h = g + a
        a = b
        b = h
    }
}

simulate_cipher()