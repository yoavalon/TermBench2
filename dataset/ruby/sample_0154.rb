def transform_coordinates(x, y, z, matrix)
  x_new = matrix[0][0] * x + matrix[0][1] * y + matrix[0][2] * z
  y_new = matrix[1][0] * x + matrix[1][1] * y + matrix[1][2] * z
  z_new = matrix[2][0] * x + matrix[2][1] * y + matrix[2][2] * z
  [x_new, y_new, z_new]
end

def apply_transformations(coord_list, matrix_list)
  transformed_coords = []
  coord_list.each do |coord|
    matrix_list.each do |matrix|
      coord = transform_coordinates(coord[0], coord[1], coord[2], matrix)
    end
    transformed_coords << coord
  end
  transformed_coords
end

def main
  coords = [[1, 2, 3], [4, 5, 6]]
  matrices = [[[1, 0, 0], [0, 1, 0], [0, 0, 1]], [[0, 0, 1], [1, 0, 0], [0, 1, 0]]]
  result = apply_transformations(coords, matrices)
  puts result
end

main