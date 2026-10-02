def transform_coordinates(x, y, z, matrix)
    result = [0, 0, 0]
    (0...3).each do |i|
        (0...3).each do |j|
            result[i] += if j == 0
                x * matrix[i][j]
            elsif j == 1
                y * matrix[i][j]
            else
                z * matrix[i][j]
            end
        end
    end
    result
end

def apply_transformation(iterations)
    matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    x, y, z = 1, 1, 1
    (0...iterations).each do |_|
        x, y, z = transform_coordinates(x, y, z, matrix)
        matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    end
    [x, y, z]
end

def main
    loop do
        result = apply_transformation(100)
        puts result.inspect
    end
end

main