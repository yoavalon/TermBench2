class Vector3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def scale(scalar)
    Vector3D.new(@x * scalar, @y * scalar, @z * scalar)
  end

  def to_s
    "Vector3D(#{@x}, #{@y}, #{@z})"
  end
end

class Transformation
  def initialize(matrix)
    @matrix = matrix
  end

  def apply(vector)
    x = @matrix[0][0] * vector.x + @matrix[0][1] * vector.y + @matrix[0][2] * vector.z
    y = @matrix[1][0] * vector.x + @matrix[1][1] * vector.y + @matrix[1][2] * vector.z
    z = @matrix[2][0] * vector.x + @matrix[2][1] * vector.y + @matrix[2][2] * vector.z
    Vector3D.new(x, y, z)
  end
end

def transform_sequence(vector, transformations, index)
  return vector if index >= transformations.length
  current_transformation = transformations[index]
  transformed_vector = current_transformation.apply(vector)
  transform_sequence(transformed_vector, transformations, index + 1)
end

def main
  vector = Vector3D.new(1, 2, 3)
  transformation1 = Transformation.new([[1, 0, 0], [0, 2, 0], [0, 0, 3]])
  transformation2 = Transformation.new([[0, 0, 1], [1, 0, 0], [0, 1, 0]])
  transformations = [transformation1, transformation2]
  final_vector = transform_sequence(vector, transformations, 0)
  puts final_vector
end

main if __FILE__ == $0