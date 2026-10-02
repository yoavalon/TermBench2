class Point3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def translate(dx, dy, dz)
    Point3D.new(@x + dx, @y + dy, @z + dz)
  end

  def rotate_x(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    Point3D.new(@x, @y * cos_a - @z * sin_a, @y * sin_a + @z * cos_a)
  end

  def rotate_y(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    Point3D.new(@x * cos_a + @z * sin_a, @y, -@x * sin_a + @z * cos_a)
  end

  def rotate_z(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    Point3D.new(@x * cos_a - @y * sin_a, @x * sin_a + @y * cos_a, @z)
  end

  def to_s
    "Point3D(#{@x}, #{@y}, #{@z})"
  end
end

def transform_sequence(point, operations, index = 0)
  return point if index == operations.length
  operation, args = operations[index]
  case operation
  when 'translate'
    point = point.translate(*args)
  when 'rotate_x'
    point = point.rotate_x(*args)
  when 'rotate_y'
    point = point.rotate_y(*args)
  when 'rotate_z'
    point = point.rotate_z(*args)
  end
  transform_sequence(point, operations, index + 1)
end

def main
  point = Point3D.new(1, 2, 3)
  operations = [['translate', [1, 1, 1]], ['rotate_x', 0.785398], ['rotate_y', 0.785398], ['rotate_z', 0.785398], ['translate', [-1, -1, -1]]]
  final_point = transform_sequence(point, operations)
  puts final_point
end

main