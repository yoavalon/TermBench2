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
  result
end

def apply_transformation
  coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  loop do
    coords = transform_coordinates(coords, matrix)
    puts coords.inspect
  end
end

apply_transformation