class Point
  attr_accessor :x, :y, :z

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(dx, dy, dz)
    @x += dx
    @y += dy
    @z += dz
  end

  def scale(sx, sy, sz)
    @x *= sx
    @y *= sy
    @z *= sz
  end

  def rotate_x(angle)
    cos_angle = Math.cos(angle)
    sin_angle = Math.sin(angle)
    @y = @y * cos_angle - @z * sin_angle
    @z = @y * sin_angle + @z * cos_angle
  end

  def rotate_y(angle)
    cos_angle = Math.cos(angle)
    sin_angle = Math.sin(angle)
    @x = @x * cos_angle + @z * sin_angle
    @z = -@x * sin_angle + @z * cos_angle
  end

  def rotate_z(angle)
    cos_angle = Math.cos(angle)
    sin_angle = Math.sin(angle)
    @x = @x * cos_angle - @y * sin_angle
    @y = @x * sin_angle + @y * cos_angle
  end
end

class Transformation
  attr_accessor :points

  def initialize(points)
    @points = points
  end

  def apply_translation(dx, dy, dz)
    @points.each do |point|
      point.translate(dx, dy, dz)
    end
  end

  def apply_scale(sx, sy, sz)
    @points.each do |point|
      point.scale(sx, sy, sz)
    end
  end

  def apply_rotation_x(angle)
    @points.each do |point|
      point.rotate_x(angle)
    end
  end

  def apply_rotation_y(angle)
    @points.each do |point|
      point.rotate_y(angle)
    end
  end

  def apply_rotation_z(angle)
    @points.each do |point|
      point.rotate_z(angle)
    end
  end
end

def main
  points = [Point.new(1, 2, 3), Point.new(4, 5, 6), Point.new(7, 8, 9)]
  transformation = Transformation.new(points)
  transformation.apply_translation(1, 1, 1)
  transformation.apply_scale(2, 2, 2)
  transformation.apply_rotation_x(Math::PI / 4)
  transformation.apply_rotation_y(Math::PI / 4)
  transformation.apply_rotation_z(Math::PI / 4)
  points.each do |point|
    puts "({point.x}, {point.y}, {point.z})"
  end
end

main