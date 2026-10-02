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

  def scale(sx, sy, sz)
    @x *= sx
    @y *= sy
    @z *= sz
  end

  def rotate(rx, ry, rz)
    cos_rx, sin_rx = [Math.cos(rx), Math.sin(rx)]
    cos_ry, sin_ry = [Math.cos(ry), Math.sin(ry)]
    cos_rz, sin_rz = [Math.cos(rz), Math.sin(rz)]
    x = @x
    y = @y
    z = @z
    @x = cos_ry * (cos_rz * x + sin_rz * y) - sin_ry * z
    @y = sin_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) + cos_rx * (cos_rz * x + sin_rz * y)
    @z = cos_rx * (cos_ry * z + sin_ry * (cos_rz * x + sin_rz * y)) - sin_rx * (cos_rz * x + sin_rz * y)
  end
end

def transform_sequence(point, transformations)
  transformations.each do |transform|
    transform_type, params = transform
    case transform_type
    when 'translate'
      point.translate(*params)
    when 'scale'
      point.scale(*params)
    when 'rotate'
      point.rotate(*params)
    end
  end
end

def main
  p = Point.new(1, 0, 0)
  transformations = [['translate', [1, 1, 1]], ['scale', [2, 2, 2]], ['rotate', [0.5, 0.5, 0.5]], ['translate', [1, 1, 1]], ['scale', [0.5, 0.5, 0.5]], ['rotate', [-0.5, -0.5, -0.5]]]
  loop do
    transform_sequence(p, transformations)
    puts "Current position: (#{p.instance_variable_get(:@x)}, #{p.instance_variable_get(:@y)}, #{p.instance_variable_get(:@z)})"
  end
end

main