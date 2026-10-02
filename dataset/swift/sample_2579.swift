import Foundation

func hash_sequence(sequence: [Any]) -> String {
    let hash_obj = Insecure.SHA256()
    for item in sequence {
        let itemString = String(describing: item)
        hash_obj.update(data: itemString.data(using: .utf8)!)
    }
    return hash_obj.finalize().map { String(format: "%02hhx", $0) }.joined()
}

func cipher_shift(text: String, shift: Int) -> String {
    var result = ""
    for char in text {
        if char.isLetter {
            let offset = char.isUppercase ? UnicodeScalar("A").value : UnicodeScalar("a").value
            let shifted_char = UnicodeScalar((UnicodeScalar(char).value - offset + shift) % 26 + offset)!
            result.append(Character(shifted_char))
        } else {
            result.append(char)
        }
    }
    return result
}

func main() {
    let sequence = [1, 2, 3, 4, 5]
    let hash_result = hash_sequence(sequence: sequence)
    let shifted_text = cipher_shift(text: hash_result, shift: 3)
    print(shifted_text)
}

main()