class CoordinateTransformer
  def initialize(x, y, z)
    @a = x
    @b = y
    @c = z
  end

  def rotate(theta)
    cos_theta = Math.cos(theta)
    sin_theta = Math.sin(theta)
    @a, @b = (@a * cos_theta - @b * sin_theta, @a * sin_theta + @b * cos_theta)
  end

  def scale(factor)
    @a *= factor
    @b *= factor
    @c *= factor
  end

  def translate(dx, dy, dz)
    @a += dx
    @b += dy
    @c += dz
  end
end

def apply_transformations(obj, rotations, scales, translations)
  rotations.each { |angle| obj.rotate(angle) }
  scales.each { |factor| obj.scale(factor) }
  translations.each { |dx, dy, dz| obj.translate(dx, dy, dz) }
end

def main
  obj = CoordinateTransformer.new(1, 2, 3)
  rotations = [0.1, 0.2, 0.3]
  scales = [1.5, 2.0, 2.5]
  translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
  apply_transformations(obj, rotations, scales, translations)
  puts "#{obj.instance_variable_get(:@a)} #{obj.instance_variable_get(:@b)} #{obj.instance_variable_get(:@c)}"
end

main