def transform3d(coords, matrix, depth)
  if depth == 0
    return coords
  end
  transformed = Array.new(3) { |j| (0...3).map { |i| coords[i] * matrix[i][j] }.sum }
  return transform3d(transformed, matrix, depth - 1)
end

start = [1, 2, 3]
mat = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
result = transform3d(start, mat, 2)
puts result