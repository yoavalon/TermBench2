def transform_coordinates(coords, matrix)
  result = []
  coords.each do |coord|
    new_coord = [0, 0, 0]
    (0..2).each do |i|
      (0..2).each do |j|
        new_coord[i] += coord[j] * matrix[i][j]
      end
    end
    result << new_coord
  end
  result
end

if __FILE__ == $0
  coords = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  puts transform_coordinates(coords, matrix).inspect
end