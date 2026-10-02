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

  def rotate(angle_x, angle_y, angle_z)
    cos_x, sin_x = Math.cos(angle_x), Math.sin(angle_x)
    cos_y, sin_y = Math.cos(angle_y), Math.sin(angle_y)
    cos_z, sin_z = Math.cos(angle_z), Math.sin(angle_z)
    x, y, z = @x, @y, @z
    @x = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    @y = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    @z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  end
end

class Transformation
  def initialize(angle_x, angle_y, angle_z)
    @angle_x = angle_x
    @angle_y = angle_y
    @angle_z = angle_z
  end

  def apply(point)
    point.rotate(@angle_x, @angle_y, @angle_z)
  end
end

def simulate_transformation
  point = Point3D.new(1.0, 1.0, 1.0)
  transformation = Transformation.new(Math::PI / 4, Math::PI / 4, Math::PI / 4)
  loop do
    transformation.apply(point)
    puts "(#{'%.10f' % point.x}, #{'%.10f' % point.y}, #{'%.10f' % point.z})"
  end
end

simulate_transformation