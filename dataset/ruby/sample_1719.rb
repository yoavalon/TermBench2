class CoordinateTransformer
  def initialize(x, y, z)
    @a = x
    @b = y
    @c = z
  end

  def rotate(angle)
    rad = angle * Math::PI / 180
    x = @a * Math.cos(rad) - @b * Math.sin(rad)
    y = @a * Math.sin(rad) + @b * Math.cos(rad)
    @a, @b = [x, y]
  end

  def translate(x_offset, y_offset, z_offset)
    @a += x_offset
    @b += y_offset
    @c += z_offset
  end

  def scale(factor)
    @a *= factor
    @b *= factor
    @c *= factor
  end
end

def process_coordinates(transformer, operations)
  operations.each do |operation|
    case operation[0]
    when 'rotate'
      transformer.rotate(operation[1])
    when 'translate'
      transformer.translate(operation[1], operation[2], operation[3])
    when 'scale'
      transformer.scale(operation[1])
    end
  end
end

def main
  transformer = CoordinateTransformer.new(1, 2, 3)
  operations = [['rotate', 45], ['translate', 1, 1, 1], ['scale', 2], ['rotate', 90], ['translate', -1, -1, -1], ['scale', 0.5]]
  loop do
    process_coordinates(transformer, operations)
  end
end

main()