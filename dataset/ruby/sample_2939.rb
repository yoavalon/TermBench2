require 'mathn'

class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    angle_rad = angle * Math::PI / 180
    cos_val = Math.cos(angle_rad)
    sin_val = Math.sin(angle_rad)
    @y = @y * cos_val - @z * sin_val
    @z = @y * sin_val + @z * cos_val
  end

  def rotate_y(angle)
    angle_rad = angle * Math::PI / 180
    cos_val = Math.cos(angle_rad)
    sin_val = Math.sin(angle_rad)
    @x = @x * cos_val + @z * sin_val
    @z = -@x * sin_val + @z * cos_val
  end

  def rotate_z(angle)
    angle_rad = angle * Math::PI / 180
    cos_val = Math.cos(angle_rad)
    sin_val = Math.sin(angle_rad)
    @x = @x * cos_val - @y * sin_val
    @y = @x * sin_val + @y * cos_val
  end
end

def generate_sequence(start, increment, length)
  sequence = []
  current = start.dup
  length.times do
    sequence << current.dup
    current = [current[0] + increment[0], current[1] + increment[1], current[2] + increment[2]]
  end
  sequence
end

def apply_transformation(sequence, angle_x, angle_y, angle_z)
  sequence.each do |coord|
    coord_obj = Coordinate.new(*coord)
    coord_obj.rotate_x(angle_x)
    coord_obj.rotate_y(angle_y)
    coord_obj.rotate_z(angle_z)
    coord.replace([coord_obj.x, coord_obj.y, coord_obj.z])
  end
end

def main
  start_point = [0, 0, 0]
  increment = [1, 1, 1]
  sequence_length = 100
  sequence = generate_sequence(start_point, increment, sequence_length)
  angle_x, angle_y, angle_z = 5, 5, 5
  loop do
    apply_transformation(sequence, angle_x, angle_y, angle_z)
    angle_x += 1
    angle_y += 1
    angle_z += 1
  end
end

main