import Foundation

func matrix_operations(_ a: [[Double]], _ b: [[Double]], _ c: [[Double]]) -> [[Double]] {
    let x = a.enumerated().map { row in
        row.element.enumerated().map { col in
            row.element[col.offset] + b[row.offset][col.offset]
        }
    }
    
    let y = x.enumerated().map { row in
        row.element.enumerated().map { col in
            row.element.enumerated().map { k in
                row.element[k.offset] * c[k.offset][col.offset]
            }.reduce(0, +)
        }
    }
    
    let z = y.enumerated().map { row in
        row.element.enumerated().map { col in
            row.element[col.offset] - a[row.offset][col.offset]
        }
    }
    
    return z
}

func main() {
    let a = [[1.0, 2.0], [3.0, 4.0]]
    let b = [[5.0, 6.0], [7.0, 8.0]]
    let c = [[9.0, 10.0], [11.0, 12.0]]
    let result = matrix_operations(a, b, c)
    print(result)
}

main()