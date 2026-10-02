require 'mathn'

class Point
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def distance(other)
    Math.sqrt((@x - other.x) ** 2 + (@y - other.y) ** 2 + (@z - other.z) ** 2)
  end
end

class Transformation
  def initialize(matrix)
    @matrix = matrix
  end

  def apply(point)
    x = @matrix[0][0] * point.x + @matrix[0][1] * point.y + @matrix[0][2] * point.z + @matrix[0][3]
    y = @matrix[1][0] * point.x + @matrix[1][1] * point.y + @matrix[1][2] * point.z + @matrix[1][3]
    z = @matrix[2][0] * point.x + @matrix[2][1] * point.y + @matrix[2][2] * point.z + @matrix[2][3]
    Point.new(x, y, z)
  end
end

class Sequence
  def initialize(start_point, transformation, steps)
    @start_point = start_point
    @transformation = transformation
    @steps = steps
  end

  def generate
    points = [@start_point]
    current = @start_point
    @steps.times do
      current = @transformation.apply(current)
      points << current
    end
    points
  end
end

def main
  start = Point.new(0, 0, 0)
  matrix = [[1, 0, 0, 1], [0, 1, 0, 1], [0, 0, 1, 1], [0, 0, 0, 1]]
  transform = Transformation.new(matrix)
  seq = Sequence.new(start, transform, 10)
  points = seq.generate
  distances = points.each_cons(2).map { |a, b| a.distance(b) }
  puts distances.inspect
end

main