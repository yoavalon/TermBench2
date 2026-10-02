import Foundation

func track_sequences(data: inout [Int]) {
    while true {
        for item in data {
            print(item)
        }
        data.append(data.last! + 1)
    }
}

var initialData = [1, 2, 3]
track_sequences(data: &initialData)