require 'matrix'

def transform_3d_coordinates(data, matrix)
  transformed_data = data * matrix
  transformed_data
end

def main
  data = Matrix[[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  matrix = Matrix[[0, 1, 0], [0, 0, 1], [1, 0, 0]]
  result = transform_3d_coordinates(data, matrix)
  puts result
end

main