class Point
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

  def rotate(angle_x, angle_y, angle_z)
    cos_x = Math.cos(angle_x)
    sin_x = Math.sin(angle_x)
    cos_y = Math.cos(angle_y)
    sin_y = Math.sin(angle_y)
    cos_z = Math.cos(angle_z)
    sin_z = Math.sin(angle_z)
    x = @x
    y = @y
    z = @z
    @x = x * cos_y * cos_z + y * (-cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z + cos_x * sin_y * cos_z)
    @y = x * cos_y * sin_z + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (-sin_x * cos_z + cos_x * sin_y * sin_z)
    @z = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
  end
end

def transform_point(point, translation, rotation)
  point.translate(translation[0], translation[1], translation[2])
  point.rotate(rotation[0], rotation[1], rotation[2])
end

def main
  p = Point.new(1.0, 2.0, 3.0)
  translation = [4.0, 5.0, 6.0]
  rotation = [0.5, 1.0, 1.5]
  transform_point(p, translation, rotation)
  puts "#{p.instance_variable_get(:@x)} #{p.instance_variable_get(:@y)} #{p.instance_variable_get(:@z)}"
end

main