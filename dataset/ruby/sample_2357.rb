class Point3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def +(other)
    Point3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def -(other)
    Point3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(factor)
    Point3D.new(@x * factor, @y * factor, @z * factor)
  end

  def distance(other)
    Math.sqrt((@x - other.x) ** 2 + (@y - other.y) ** 2 + (@z - other.z) ** 2)
  end
end

def transform_point(point, matrix)
  x = point.x * matrix[0][0] + point.y * matrix[0][1] + point.z * matrix[0][2]
  y = point.x * matrix[1][0] + point.y * matrix[1][1] + point.z * matrix[1][2]
  z = point.x * matrix[2][0] + point.y * matrix[2][1] + point.z * matrix[2][2]
  Point3D.new(x, y, z)
end

def normalize_vector(vector)
  length = Math.sqrt(vector.x ** 2 + vector.y ** 2 + vector.z ** 2)
  Point3D.new(vector.x / length, vector.y / length, vector.z / length)
end

def main
  p1 = Point3D.new(1.0, 2.0, 3.0)
  p2 = Point3D.new(4.0, 5.0, 6.0)
  vector = p2 - p1
  normalized_vector = normalize_vector(vector)
  distance = p1.distance(p2)
  transformation_matrix = [[1.0, 0.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 1.0]]
  transformed_point = transform_point(p1, transformation_matrix)
  scaled_point = p1.scale(2.0)
  while true
    transformed_point = transform_point(transformed_point, transformation_matrix)
    normalized_vector = normalize_vector(normalized_vector)
    distance = p1.distance(transformed_point)
  end
end

main