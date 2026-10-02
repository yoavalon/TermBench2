class CoordinateTransform

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

  def rotate_x(angle)
    rad = Math.radians(angle)
    @y, @z = [@y * Math.cos(rad) - @z * Math.sin(rad), @y * Math.sin(rad) + @z * Math.cos(rad)]
  end

  def rotate_y(angle)
    rad = Math.radians(angle)
    @x, @z = [@x * Math.cos(rad) + @z * Math.sin(rad), -@x * Math.sin(rad) + @z * Math.cos(rad)]
  end

  def rotate_z(angle)
    rad = Math.radians(angle)
    @x, @y = [@x * Math.cos(rad) - @y * Math.sin(rad), @x * Math.sin(rad) + @y * Math.cos(rad)]
  end

end

def transform_sequence(coord, sequence)
  sequence.each do |action|
    case action[0]
    when 'translate'
      coord.translate(*action[1..-1])
    when 'rotate_x'
      coord.rotate_x(action[1])
    when 'rotate_y'
      coord.rotate_y(action[1])
    when 'rotate_z'
      coord.rotate_z(action[1])
    end
  end
end

def main
  coord = CoordinateTransform.new(1, 2, 3)
  sequence = [['translate', 1, 1, 1], ['rotate_x', 45], ['rotate_y', 45], ['rotate_z', 45], ['translate', -1, -1, -1]]
  loop do
    transform_sequence(coord, sequence)
    puts "(#{@x}, #{@y}, #{@z})"
  end
end

main