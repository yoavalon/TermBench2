require 'mathn'

class Vector3D
  def initialize(x, y, z)
    @x = x
    @y = y
    @z = z
  end

  def add(other)
    Vector3D.new(@x + other.x, @y + other.y, @z + other.z)
  end

  def subtract(other)
    Vector3D.new(@x - other.x, @y - other.y, @z - other.z)
  end

  def scale(factor)
    Vector3D.new(@x * factor, @y * factor, @z * factor)
  end

  def magnitude
    Math.sqrt(@x**2 + @y**2 + @z**2)
  end

  def normalize
    mag = magnitude
    mag != 0 ? Vector3D.new(@x / mag, @y / mag, @z / mag) : Vector3D.new(0, 0, 0)
  end
end

def apply_rotation(matrix, vector)
  Vector3D.new(matrix[0][0] * vector.x + matrix[0][1] * vector.y + matrix[0][2] * vector.z, 
                matrix[1][0] * vector.x + matrix[1][1] * vector.y + matrix[1][2] * vector.z, 
                matrix[2][0] * vector.x + matrix[2][1] * vector.y + matrix[2][2] * vector.z)
end

def generate_rotation_matrix(angle_x, angle_y, angle_z)
  cx, sx = Math.cos(angle_x), Math.sin(angle_x)
  cy, sy = Math.cos(angle_y), Math.sin(angle_y)
  cz, sz = Math.cos(angle_z), Math.sin(angle_z)
  [[cx * cy, cx * sy * sz - sx * cz, cx * sy * cz + sx * sz], 
   [sx * cy, sx * sy * sz + cx * cz, sx * sy * cz - cx * sz], 
   [-sy, cy * sz, cy * cz]]
end

def transform_point(point, rotation_angles, translation_vector)
  rotation_matrix = generate_rotation_matrix(*rotation_angles)
  rotated_point = apply_rotation(rotation_matrix, point)
  translated_point = rotated_point.add(translation_vector)
  translated_point
end

def main
  point = Vector3D.new(1, 2, 3)
  rotation_angles = [Math::PI / 4, Math::PI / 3, Math::PI / 6]
  translation_vector = Vector3D.new(4, 5, 6)
  transformed_point = transform_point(point, rotation_angles, translation_vector)
  puts "Transformed Point: (#{transformed_point.x}, #{transformed_point.y}, #{transformed_point.z})"
end

main