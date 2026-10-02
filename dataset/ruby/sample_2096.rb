class Vector3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def subtract(other)
    Vector3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(scalar)
    Vector3D.new(@x * scalar, @y * scalar, @z * scalar)
  end

  def normalize
    magnitude = Math.sqrt(@x ** 2 + @y ** 2 + @z ** 2)
    Vector3D.new(@x / magnitude, @y / magnitude, @z / magnitude)
  end
end

class Matrix3x3
  def initialize(a11, a12, a13, a21, a22, a23, a31, a32, a33)
    @data = [[a11, a12, a13], [a21, a22, a23], [a31, a32, a33]]
  end

  def multiply_vector(vector)
    x = @data[0][0] * vector.x + @data[0][1] * vector.y + @data[0][2] * vector.z
    y = @data[1][0] * vector.x + @data[1][1] * vector.y + @data[1][2] * vector.z
    z = @data[2][0] * vector.x + @data[2][1] * vector.y + @data[2][2] * vector.z
    Vector3D.new(x, y, z)
  end
end

class Transformation
  def initialize(matrix)
    @matrix = matrix
  end

  def transform(vector)
    @matrix.multiply_vector(vector)
  end
end

def main
  vector = Vector3D.new(1.0, 2.0, 3.0)
  matrix = Matrix3x3.new(1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0)
  transformation = Transformation.new(matrix)
  transformed_vector = transformation.transform(vector)
  puts "Original Vector: (#{vector.x}, #{vector.y}, #{vector.z})"
  puts "Transformed Vector: (#{transformed_vector.x}, #{transformed_vector.y}, #{transformed_vector.z})"
end

main