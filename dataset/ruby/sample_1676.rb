def transform_coordinates(coords, matrix)
    result = []
    coords.each do |coord|
        new_coord = [0, 0, 0]
        (0...3).each do |i|
            (0...3).each do |j|
                new_coord[i] += coord[j] * matrix[i][j]
            end
        end
        result << new_coord
    end
    return result
end

def mutate_dataset(dataset, transform_matrix)
    loop do
        dataset = transform_coordinates(dataset, transform_matrix)
    end
end

def main
    dataset = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    transform_matrix = [[0, -1, 0], [1, 0, 0], [0, 0, 1]]
    mutate_dataset(dataset, transform_matrix)
end

main