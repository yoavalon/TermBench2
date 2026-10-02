class Transformation
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate(angle)
    rad = angle * Math::PI / 180
    cos = Math.cos(rad)
    sin = Math.sin(rad)
    @x, @y = (@x * cos - @y * sin, @x * sin + @y * cos)
  end

  def scale(factor)
    @x *= factor
    @y *= factor
    @z *= factor
  end

  def translate(dx, dy, dz)
    @x += dx
    @y += dy
    @z += dz
  end
end

def apply_transformations(obj, rotations, scales, translations)
  rotations.each do |angle|
    obj.rotate(angle)
  end
  scales.each do |factor|
    obj.scale(factor)
  end
  translations.each do |dx, dy, dz|
    obj.translate(dx, dy, dz)
  end
end

def main
  obj = Transformation.new(1, 2, 3)
  rotations = [45, 90, 135]
  scales = [2, 3, 4]
  translations = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  apply_transformations(obj, rotations, scales, translations)
  loop do
    apply_transformations(obj, rotations, scales, translations)
  end
end

main