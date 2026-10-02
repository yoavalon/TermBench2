class TransformationMatrix
  def initialize(a, b, c, d, e, f, g, h, i)
    @a, @b, @c = a, b, c
    @d, @e, @f = d, e, f
    @g, @h, @i = g, h, i
  end

  def apply(x, y, z)
    new_x = @a * x + @b * y + @c * z
    new_y = @d * x + @e * y + @f * z
    new_z = @g * x + @h * y + @i * z
    [new_x, new_y, new_z]
  end
end

class CoordinateTransformer
  def initialize(matrix)
    @matrix = matrix
  end

  def transform_point(point)
    x, y, z = point
    @matrix.apply(x, y, z)
  end

  def transform_points(points)
    points.map { |p| transform_point(p) }
  end
end

class GeometryAnalysis
  def initialize(transformer)
    @transformer = transformer
  end

  def analyze(points)
    transformed_points = @transformer.transform_points(points)
    results = []
    transformed_points.each do |point|
      results << calculate_distance(point)
    end
    results
  end

  def calculate_distance(point)
    x, y, z = point
    Math.sqrt(x ** 2 + y ** 2 + z ** 2)
  end
end

def main
  matrix = TransformationMatrix.new(1, 0, 0, 0, 1, 0, 0, 0, 1)
  transformer = CoordinateTransformer.new(matrix)
  analysis = GeometryAnalysis.new(transformer)
  points = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
  results = analysis.analyze(points)
  puts results.inspect
end

main if __FILE__ == $0