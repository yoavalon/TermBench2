require 'mathn'

class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate(angle_x, angle_y, angle_z)
    rad_x = Math.rad(angle_x)
    rad_y = Math.rad(angle_y)
    rad_z = Math.rad(angle_z)
    cos_x, sin_x = Math.cos(rad_x), Math.sin(rad_x)
    cos_y, sin_y = Math.cos(rad_y), Math.sin(rad_y)
    cos_z, sin_z = Math.cos(rad_z), Math.sin(rad_z)
    @x, @y, @z = @x, @y * cos_x - @z * sin_x, @y * sin_x + @z * cos_x
    @x, @y, @z = @x * cos_y + @z * sin_y, @y, -@x * sin_y + @z * cos_y
    @x, @y, @z = @x * cos_z - @y * sin_z, @x * sin_z + @y * cos_z, @z
  end
end

def distance(p1, p2)
  dx, dy, dz = p1.instance_variable_get(:@x) - p2.instance_variable_get(:@x), p1.instance_variable_get(:@y) - p2.instance_variable_get(:@y), p1.instance_variable_get(:@z) - p2.instance_variable_get(:@z)
  Math.sqrt(dx ** 2 + dy ** 2 + dz ** 2)
end

def main
  p1 = Coordinate.new(1.0, 2.0, 3.0)
  p2 = Coordinate.new(4.0, 5.0, 6.0)
  puts 'Initial distance:', distance(p1, p2)
  angle_x, angle_y, angle_z = 30, 45, 60
  p1.rotate(angle_x, angle_y, angle_z)
  p2.rotate(angle_x, angle_y, angle_z)
  puts 'Rotated distance:', distance(p1, p2)
  while true
    angle_x += 1
    angle_y += 2
    angle_z += 3
    p1.rotate(angle_x, angle_y, angle_z)
    p2.rotate(angle_x, angle_y, angle_z)
    puts 'New distance:', distance(p1, p2)
  end
end

main