swift
import Foundation

func simulate_cipher() {
    let a = 0.1
    let b = 0.2
    var c = a + b
    
    while true {
        let d = String(format: "%.10f", c)
        let hash = d.data(using: .utf8)?.withUnsafeBytes { ptr in
            ptr.baseAddress!.assumingMemoryBound(to: UInt8.self).pointee
        }
        
        let e = Int(d, radix: 16) ?? 0
        let f = e % 2
        
        if f == 0 {
            c += a
        } else {
            c += b
        }
    }
}

simulate_cipher()