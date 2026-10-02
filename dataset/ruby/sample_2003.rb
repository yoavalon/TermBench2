class Transform
  def initialize(matrix)
    @matrix = matrix
  end

  def apply(vector)
    (0..2).map { |i| (0..2).sum { |j| @matrix[i][j] * vector[j] } }
  end
end

class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def to_vector
    [@x, @y, @z]
  end

  def from_vector(vector)
    @x, @y, @z = vector
  end
end

def create_rotation_matrix(angle, axis)
  cos_a = 1.0
  sin_a = 0.0
  if axis == 'x'
    cos_a = 1.0
    sin_a = angle
  elsif axis == 'y'
    cos_a = 1.0
    sin_a = angle
  elsif axis == 'z'
    cos_a = 1.0
    sin_a = angle
  end
  [[1, 0, 0], [0, cos_a, -sin_a], [0, sin_a, cos_a]]
end

def main
  coord = Coordinate.new(1.0, 2.0, 3.0)
  vector = coord.to_vector
  rotation_matrix = create_rotation_matrix(0.5, 'z')
  transform = Transform.new(rotation_matrix)
  new_vector = transform.apply(vector)
  coord.from_vector(new_vector)
  puts "#{coord.instance_variable_get(:@x)} #{coord.instance_variable_get(:@y)} #{coord.instance_variable_get(:@z)}"
end

main if __FILE__ == $0