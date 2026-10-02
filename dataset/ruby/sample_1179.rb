require 'mathn'

class Transform3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    sin_a = Math.sin(angle)
    cos_a = Math.cos(angle)
    @y, @z = (cos_a * @y - sin_a * @z, sin_a * @y + cos_a * @z)
  end

  def rotate_y(angle)
    sin_a = Math.sin(angle)
    cos_a = Math.cos(angle)
    @x, @z = (cos_a * @x + sin_a * @z, -sin_a * @x + cos_a * @z)
  end

  def rotate_z(angle)
    sin_a = Math.sin(angle)
    cos_a = Math.cos(angle)
    @x, @y = (cos_a * @x - sin_a * @y, sin_a * @x + cos_a * @y)
  end
end

def recursive_transform(coord, angle, depth)
  coord.rotate_x(angle)
  coord.rotate_y(angle)
  coord.rotate_z(angle)
  if depth > 0
    recursive_transform(coord, angle, depth - 1)
  end
end

def main
  coord = Transform3D.new(1.0, 0.0, 0.0)
  angle = Math::PI / 4
  depth = 1000
  recursive_transform(coord, angle, depth)
  loop do
  end
end

main