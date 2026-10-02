require 'matrix'

def transform_coordinates(coords, matrix)
  coords * matrix
end

def main
  coords = Matrix[[1, 2, 3], [4, 5, 6]]
  matrix = Matrix[[0, 1, 0], [1, 0, 0], [0, 0, 1]]
  result = transform_coordinates(coords, matrix)
  puts result
end

main