def transform_3d(point, matrix)
    result = [0, 0, 0]
    for i in 0...3
        for j in 0...3
            result[i] += point[j] * matrix[i][j]
        end
    end
    return result
end

def main()
    point = [1.0, 2.0, 3.0]
    matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
    transformed = transform_3d(point, matrix)
    puts transformed
end

main()