def transform_sequence(points, matrix)
  result = []
  points.each do |point|
    transformed = matrix.map { |row| row.zip(point).map { |a, b| a * b }.sum }
    result << transformed
  end
  result
end

sequence = [[1, 2, 3], [4, 5, 6]]
matrix = [[0, 1, 0], [0, 0, 1], [1, 0, 0]]
transformed_sequence = transform_sequence(sequence, matrix)
puts transformed_sequence.inspect