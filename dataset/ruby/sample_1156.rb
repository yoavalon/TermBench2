class Coordinate
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    rad = angle * Math::PI / 180
    cos_val = Math.cos(rad)
    sin_val = Math.sin(rad)
    Coordinate.new(@x, @y * cos_val - @z * sin_val, @y * sin_val + @z * cos_val)
  end

  def rotate_y(angle)
    rad = angle * Math::PI / 180
    cos_val = Math.cos(rad)
    sin_val = Math.sin(rad)
    Coordinate.new(@x * cos_val + @z * sin_val, @y, -@x * sin_val + @z * cos_val)
  end

  def rotate_z(angle)
    rad = angle * Math::PI / 180
    cos_val = Math.cos(rad)
    sin_val = Math.sin(rad)
    Coordinate.new(@x * cos_val - @y * sin_val, @x * sin_val + @y * cos_val, @z)
  end
end

def transform(coord, angle, axis)
  case axis
  when 'x'
    coord.rotate_x(angle)
  when 'y'
    coord.rotate_y(angle)
  when 'z'
    coord.rotate_z(angle)
  else
    coord
  end
end

def recursive_transform(coord, angle, axis)
  new_coord = transform(coord, angle, axis)
  recursive_transform(new_coord, angle, axis)
end

def main
  initial_coord = Coordinate.new(1, 0, 0)
  final_coord = recursive_transform(initial_coord, 90, 'z')
  puts "#{final_coord.x} #{final_coord.y} #{final_coord.z}"
end

main