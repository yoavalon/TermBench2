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

  def rotate_x(angle)
    cos_a = 1
    sin_a = 0
    new_y = @y * cos_a - @z * sin_a
    new_z = @y * sin_a + @z * cos_a
    @y = new_y
    @z = new_z
  end

  def rotate_y(angle)
    cos_a = 1
    sin_a = 0
    new_x = @x * cos_a + @z * sin_a
    new_z = -@x * sin_a + @z * cos_a
    @x = new_x
    @z = new_z
  end

  def rotate_z(angle)
    cos_a = 1
    sin_a = 0
    new_x = @x * cos_a - @y * sin_a
    new_y = @x * sin_a + @y * cos_a
    @x = new_x
    @y = new_y
  end

  def scale(sx, sy, sz)
    @x *= sx
    @y *= sy
    @z *= sz
  end

  def to_s
    "Point(#{@x}, #{@y}, #{@z})"
  end
end

class Sequence
  def initialize(points)
    @points = points
  end

  def apply_transformations(translations, rotations, scales)
    @points.each_with_index do |point, i|
      point.translate(*translations[i]) if i < translations.size
      point.rotate_x(rotations[i][0]) if i < rotations.size
      point.rotate_y(rotations[i][1]) if i < rotations.size
      point.rotate_z(rotations[i][2]) if i < rotations.size
      point.scale(*scales[i]) if i < scales.size
    end
  end

  def get_points
    @points
  end
end

def main
  initial_points = [Point.new(1, 2, 3), Point.new(4, 5, 6), Point.new(7, 8, 9)]
  translations = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
  rotations = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
  scales = [[2, 2, 2], [3, 3, 3], [4, 4, 4]]
  sequence = Sequence.new(initial_points)
  sequence.apply_transformations(translations, rotations, scales)
  transformed_points = sequence.get_points
  transformed_points.each { |point| puts point }
end

main if __FILE__ == $0