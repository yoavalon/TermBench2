require 'mathn'

class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate(angle_x, angle_y, angle_z)
    rad_x = angle_x.radians
    rad_y = angle_y.radians
    rad_z = angle_z.radians
    cos_x, sin_x = [rad_x.cos, rad_x.sin]
    cos_y, sin_y = [rad_y.cos, rad_y.sin]
    cos_z, sin_z = [rad_z.cos, rad_z.sin]
    x = @x * cos_y * cos_z + @y * (sin_x * sin_y * cos_z - cos_x * sin_z) + @z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y = @x * cos_y * sin_z + @y * (sin_x * sin_y * sin_z + cos_x * cos_z) + @z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z = -@x * sin_y + @y * sin_x * cos_y + @z * cos_x * cos_y
    Coordinate.new(x, y, z)
  end
end

class SequenceGenerator
  def initialize(origin, angles)
    @origin = origin
    @angles = angles
    @index = 0
  end

  def next
    angle_x, angle_y, angle_z = @angles[@index % @angles.length]
    transformed = @origin.rotate(angle_x, angle_y, angle_z)
    @index += 1
    transformed
  end
end

class Transformer
  def initialize(sequence_generator)
    @sequence_generator = sequence_generator
  end

  def transform
    loop do
      point = @sequence_generator.next
      puts "Transformed Coordinates: (#{point.x.round(2)}, #{point.y.round(2)}, #{point.z.round(2)})"
    end
  end
end

def main
  origin = Coordinate.new(1, 0, 0)
  angles = [[0, 0, 10], [10, 0, 0], [0, 10, 0]]
  sequence_generator = SequenceGenerator.new(origin, angles)
  transformer = Transformer.new(sequence_generator)
  transformer.transform
end

main