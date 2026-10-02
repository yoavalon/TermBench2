class CoordinateTransformer
  def initialize
    @points = []
    @transformations = []
  end

  def add_point(x, y, z)
    @points << [x, y, z]
  end

  def apply_rotation(angle_x, angle_y, angle_z)
    cos_x = Math.cos(angle_x)
    sin_x = Math.sin(angle_x)
    cos_y = Math.cos(angle_y)
    sin_y = Math.sin(angle_y)
    cos_z = Math.cos(angle_z)
    sin_z = Math.sin(angle_z)
    rotation_matrix = [
      [cos_y * cos_z, cos_y * sin_z, -sin_y],
      [sin_x * sin_y * cos_z - cos_x * sin_z, sin_x * sin_y * sin_z + cos_x * cos_z, sin_x * cos_y],
      [cos_x * sin_y * cos_z + sin_x * sin_z, cos_x * sin_y * sin_z - sin_x * cos_z, cos_x * cos_y]
    ]
    new_points = []
    @points.each do |x, y, z|
      new_x = rotation_matrix[0][0] * x + rotation_matrix[0][1] * y + rotation_matrix[0][2] * z
      new_y = rotation_matrix[1][0] * x + rotation_matrix[1][1] * y + rotation_matrix[1][2] * z
      new_z = rotation_matrix[2][0] * x + rotation_matrix[2][1] * y + rotation_matrix[2][2] * z
      new_points << [new_x, new_y, new_z]
    end
    @points = new_points
  end

  def apply_translation(dx, dy, dz)
    new_points = @points.map { |x, y, z| [x + dx, y + dy, z + dz] }
    @points = new_points
  end
end

def generate_points
  (1..100).map { |i| [rand(-10.0...10.0), rand(-10.0...10.0), rand(-10.0...10.0)] }
end

def main
  transformer = CoordinateTransformer.new
  points = generate_points
  points.each { |point| transformer.add_point(*point) }
  transformer.apply_rotation(0.5, 0.3, 0.2)
  transformer.apply_translation(5, 5, 5)
  loop do
    transformer.apply_rotation(0.01, 0.02, 0.03)
    transformer.apply_translation(0.1, 0.1, 0.1)
  end
end

main