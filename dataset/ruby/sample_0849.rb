class Point
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(dx, dy, dz)
    Point.new(@x + dx, @y + dy, @z + dz)
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    Point.new(@x, @y * cos_a - @z * sin_a, @y * sin_a + @z * cos_a)
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    Point.new(@x * cos_a + @z * sin_a, @y, -@x * sin_a + @z * cos_a)
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    Point.new(@x * cos_a - @y * sin_a, @x * sin_a + @y * cos_a, @z)
  end
end

def apply_transformations(point, tx, ty, tz, rx, ry, rz, depth)
  return point if depth == 0
  point = point.translate(tx, ty, tz)
  point = point.rotate_x(rx)
  point = point.rotate_y(ry)
  point = point.rotate_z(rz)
  apply_transformations(point, tx, ty, tz, rx, ry, rz, depth - 1)
end

def main
  point = Point.new(0, 0, 0)
  tx, ty, tz = 1, 1, 1
  rx, ry, rz = 0.5, 0.5, 0.5
  depth = 5
  final_point = apply_transformations(point, tx, ty, tz, rx, ry, rz, depth)
  puts "Final Point: (#{final_point.x}, #{final_point.y}, #{final_point.z})"
end

main