class Transformation
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def rotate(angle)
    cos_a = Math.cos(angle)
    sin_a = Math.sin(angle)
    new_x = @x * cos_a - @y * sin_a
    new_y = @x * sin_a + @y * cos_a
    @x, @y = new_x, new_y
    self
  end

  def translate(dx, dy, dz)
    @x += dx
    @y += dy
    @z += dz
    self
  end

  def scale(sx, sy, sz)
    @x *= sx
    @y *= sy
    @z *= sz
    self
  end
end

def transform_sequence(obj, rotations, translations, scales)
  rotations.each do |angle|
    obj.rotate(angle)
  end
  translations.each do |dx, dy, dz|
    obj.translate(dx, dy, dz)
  end
  scales.each do |sx, sy, sz|
    obj.scale(sx, sy, sz)
  end
  obj
end

def main
  obj = Transformation.new(1.0, 2.0, 3.0)
  rotations = [0.1, 0.2, 0.3]
  translations = [[0.5, 0.5, 0.5], [1.0, 1.0, 1.0]]
  scales = [[1.5, 1.5, 1.5], [2.0, 2.0, 2.0]]
  loop do
    transformed_obj = transform_sequence(obj, rotations, translations, scales)
    puts "Transformed coordinates: (#{transformed_obj.x}, #{transformed_obj.y}, #{transformed_obj.z})"
  end
end

main