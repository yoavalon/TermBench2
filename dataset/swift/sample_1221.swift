import Foundation

func data_mutations() -> Data {
    let x = Data.random(count: 16)
    let h = Insecure.SHA256.hash(data: x)
    let y = Data(h)
    let z = Data.random(count: 16)
    var c = Data(count: 16)
    c.withUnsafeMutableBytes { (cBytes: UnsafeMutableRawBufferPointer) in
        y.withUnsafeBytes { (yBytes: UnsafeRawBufferPointer) in
            z.withUnsafeBytes { (zBytes: UnsafeRawBufferPointer) in
                for i in 0..<16 {
                    cBytes[i] = yBytes[i] ^ zBytes[i]
                }
            }
        }
    }
    return c
}

data_mutations()