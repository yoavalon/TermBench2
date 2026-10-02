require 'matrix'

def transform_coordinates(points, matrix)
  points * matrix.transpose
end

def main
  points = Matrix.rows([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
  matrix = Matrix.rows([[0, 1, 0], [0, 0, 1], [1, 0, 0]])
  transformed = transform_coordinates(points, matrix)
  puts transformed.to_a
end

main