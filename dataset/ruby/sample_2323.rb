class Transformation
  def initialize(matrix)
    @matrix = matrix
  end

  def apply(vector)
    result = [0, 0, 0]
    (0...3).each do |i|
      (0...3).each do |j|
        result[i] += @matrix[i][j] * vector[j]
      end
    end
    result
  end
end

class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def to_list
    [@x, @y, @z]
  end
end

def generate_transformation_matrix(angle_x, angle_y, angle_z)
  cos_x, sin_x = Math.cos(angle_x), Math.sin(angle_x)
  cos_y, sin_y = Math.cos(angle_y), Math.sin(angle_y)
  cos_z, sin_z = Math.cos(angle_z), Math.sin(angle_z)
  [
    [cos_y * cos_z, cos_y * sin_z, -sin_y],
    [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
    [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]
  ]
end

def main
  angle_x, angle_y, angle_z = 0.1, 0.2, 0.3
  transformation_matrix = generate_transformation_matrix(angle_x, angle_y, angle_z)
  transformation = Transformation.new(transformation_matrix)
  coordinate = Coordinate.new(1.0, 2.0, 3.0)
  loop do
    transformed_vector = transformation.apply(coordinate.to_list)
    coordinate = Coordinate.new(transformed_vector[0], transformed_vector[1], transformed_vector[2])
  end
end

main