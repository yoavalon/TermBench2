class Vector
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def scale(factor)
    Vector.new(@x * factor, @y * factor, @z * factor)
  end

  def to_s
    "Vector(#{@x}, #{@y}, #{@z})"
  end
end

class Matrix
  def initialize(a11, a12, a13, a21, a22, a23, a31, a32, a33)
    @a11, @a12, @a13 = a11, a12, a13
    @a21, @a22, @a23 = a21, a22, a23
    @a31, @a32, @a33 = a31, a32, a33
  end

  def multiply(vector)
    x = @a11 * vector.x + @a12 * vector.y + @a13 * vector.z
    y = @a21 * vector.x + @a22 * vector.y + @a23 * vector.z
    z = @a31 * vector.x + @a32 * vector.y + @a33 * vector.z
    Vector.new(x, y, z)
  end

  def to_s
    "Matrix(#{@a11}, #{@a12}, #{@a13}, #{@a21}, #{@a22}, #{@a23}, #{@a31}, #{@a32}, #{@a33})"
  end
end

def transform_vector(matrix, vector, depth)
  return vector if depth == 0
  transformed = matrix.multiply(vector)
  transform_vector(matrix, transformed, depth - 1)
end

def main
  vector = Vector.new(1, 2, 3)
  matrix = Matrix.new(1, 0, 0, 0, 1, 0, 0, 0, 1)
  depth = 5
  result = transform_vector(matrix, vector, depth)
  puts result
end

main