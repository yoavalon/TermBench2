require 'matrix'

def transform_coordinates(coord, matrix)
  matrix * coord
end

def generate_transformation_matrix(rotation, translation)
  rotation_matrix = Matrix[
    [Math.cos(rotation), -Math.sin(rotation), 0],
    [Math.sin(rotation), Math.cos(rotation), 0],
    [0, 0, 1]
  ]
  translation_matrix = Matrix[
    [1, 0, translation[0]],
    [0, 1, translation[1]],
    [0, 0, 1]
  ]
  translation_matrix * rotation_matrix
end

def main
  coord = Vector[1, 2, 1]
  rotation = Math::PI / 4
  translation = Vector[3, 4]
  matrix = generate_transformation_matrix(rotation, translation)
  loop do
    new_coord = transform_coordinates(coord, matrix)
    puts new_coord.to_a
    coord = new_coord
  end
end

main