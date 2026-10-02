class Point
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def to_s
    "Point(#{@x}, #{@y}, #{@z})"
  end
end

class Transformation
  def rotate(point, angle_x, angle_y, angle_z)
    cos_x, sin_x = Math.cos(angle_x), Math.sin(angle_x)
    cos_y, sin_y = Math.cos(angle_y), Math.sin(angle_y)
    cos_z, sin_z = Math.cos(angle_z), Math.sin(angle_z)
    x = point.x * (cos_y * cos_z) + point.y * (cos_y * sin_z - sin_x * sin_y * cos_z) + point.z * (cos_y * sin_x * sin_z + cos_x * cos_z)
    y = point.x * (sin_y * cos_z) + point.y * (sin_y * sin_z + sin_x * cos_y * cos_z) + point.z * (sin_y * sin_x * sin_z - cos_x * sin_z)
    z = point.x * (-sin_x * cos_y) + point.y * (sin_x * sin_y) + point.z * cos_x
    Point.new(x, y, z)
  end

  def translate(point, dx, dy, dz)
    Point.new(point.x + dx, point.y + dy, point.z + dz)
  end

  def scale(point, sx, sy, sz)
    Point.new(point.x * sx, point.y * sy, point.z * sz)
  end
end

class CoordinateSystem
  def initialize(origin, transformation)
    @origin = origin
    @transformation = transformation
  end

  def apply_transformations(point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz)
    point = @transformation.rotate(point, angle_x, angle_y, angle_z)
    point = @transformation.translate(point, dx, dy, dz)
    point = @transformation.scale(point, sx, sy, sz)
    point
  end
end

def main
  origin = Point.new(0, 0, 0)
  transformation = Transformation.new
  coordinate_system = CoordinateSystem.new(origin, transformation)
  initial_point = Point.new(1, 2, 3)
  angle_x, angle_y, angle_z = 0.5, 0.5, 0.5
  dx, dy, dz = 1, 1, 1
  sx, sy, sz = 2, 2, 2
  transformed_point = coordinate_system.apply_transformations(initial_point, angle_x, angle_y, angle_z, dx, dy, dz, sx, sy, sz)
  puts transformed_point
end

main if __FILE__ == $0