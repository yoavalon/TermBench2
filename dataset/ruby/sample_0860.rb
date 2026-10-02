class Transformation
  def initialize(matrix)
    @matrix = matrix
  end

  def apply(point)
    x, y, z = point
    new_x = @matrix[0][0] * x + @matrix[0][1] * y + @matrix[0][2] * z + @matrix[0][3]
    new_y = @matrix[1][0] * x + @matrix[1][1] * y + @matrix[1][2] * z + @matrix[1][3]
    new_z = @matrix[2][0] * x + @matrix[2][1] * y + @matrix[2][2] * z + @matrix[2][3]
    [new_x, new_y, new_z]
  end
end

class Point
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def transform(matrix)
    transformed = Transformation.new(matrix).apply([@x, @y, @z])
    Point.new(*transformed)
  end
end

def recursive_transform(point, matrix, depth)
  if depth == 0
    point
  else
    new_point = point.transform(matrix)
    recursive_transform(new_point, matrix, depth - 1)
  end
end

def main
  matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]]
  initial_point = Point.new(0, 0, 0)
  depth = 5
  result = recursive_transform(initial_point, matrix, depth)
  puts "Transformed point: (#{result.x}, #{result.y}, #{result.z})"
end

main