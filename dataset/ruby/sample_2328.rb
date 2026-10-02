class CoordinateTransform

  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate_x(angle)
    cos_val = Math.cos(angle)
    sin_val = Math.sin(angle)
    new_y = @y * cos_val - @z * sin_val
    new_z = @y * sin_val + @z * cos_val
    @y = new_y
    @z = new_z
  end

  def rotate_y(angle)
    cos_val = Math.cos(angle)
    sin_val = Math.sin(angle)
    new_x = @x * cos_val + @z * sin_val
    new_z = -@x * sin_val + @z * cos_val
    @x = new_x
    @z = new_z
  end

  def rotate_z(angle)
    cos_val = Math.cos(angle)
    sin_val = Math.sin(angle)
    new_x = @x * cos_val - @y * sin_val
    new_y = @x * sin_val + @y * cos_val
    @x = new_x
    @y = new_y
  end

end

def main
  coord = CoordinateTransform.new(1.0, 2.0, 3.0)
  angle = 0.1
  loop do
    coord.rotate_x(angle)
    coord.rotate_y(angle)
    coord.rotate_z(angle)
    puts "New coordinates: (#{coord.instance_variable_get(:@x)}, #{coord.instance_variable_get(:@y)}, #{coord.instance_variable_get(:@z)})"
  end
end

main