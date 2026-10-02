def transform_coordinates(x, y, z, rotation, translation)
  sin_rot = Math.sin(rotation)
  cos_rot = Math.cos(rotation)
  x_new = x * cos_rot - y * sin_rot + translation[0]
  y_new = x * sin_rot + y * cos_rot + translation[1]
  z_new = z + translation[2]
  return [x_new, y_new, z_new]
end

def continuous_transformation
  x, y, z = 0, 0, 0
  rotation = 0
  translation = [1, 1, 1]
  loop do
    x, y, z = transform_coordinates(x, y, z, rotation, translation)
    rotation += 0.01
    translation = Array.new(3) { rand(-1.0..1.0) }
  end
end

def main
  continuous_transformation
end

main