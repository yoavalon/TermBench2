require 'mathn'

class Point3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def distance(other)
    Math.sqrt((@x - other.x) ** 2 + (@y - other.y) ** 2 + (@z - other.z) ** 2)
  end
end

class RotationMatrix
  def initialize(angle, axis)
    @angle = angle
    @axis = axis
  end

  def apply(point)
    x, y, z = point.x, point.y, point.z
    a, b, c = @axis.x, @axis.y, @axis.z
    s = Math.sin(@angle)
    c = Math.cos(@angle)
    t = 1 - c
    ax = a * x
    ay = a * y
    az = a * z
    bx = b * x
    by = b * y
    bz = b * z
    cx = c * x
    cy = c * y
    cz = c * z
    Point3D.new(t * ax * a + c * cx + s * (by * c - bz * b), t * ay * a + s * (az * b - ax * c) + c * cy, t * az * a + s * (ax * b - ay * c) + c * cz)
  end
end

def transform_point(point, rotations)
  rotations.each do |rotation|
    point = rotation.apply(point)
  end
  point
end

def main
  p = Point3D.new(1.0, 2.0, 3.0)
  rotations = [RotationMatrix.new(Math::PI / 4, Point3D.new(1, 0, 0)), RotationMatrix.new(Math::PI / 4, Point3D.new(0, 1, 0)), RotationMatrix.new(Math::PI / 4, Point3D.new(0, 0, 1))]
  loop do
    p = transform_point(p, rotations)
    puts "#{p.x} #{p.y} #{p.z}"
  end
end

main