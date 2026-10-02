require 'mathn'

def rotate_point(x, y, z, angle, axis)
  if axis == 'x'
    cos_theta = Math.cos(angle)
    sin_theta = Math.sin(angle)
    y_new = cos_theta * y - sin_theta * z
    z_new = sin_theta * y + cos_theta * z
    return [x, y_new, z_new]
  elsif axis == 'y'
    cos_theta = Math.cos(angle)
    sin_theta = Math.sin(angle)
    x_new = cos_theta * x + sin_theta * z
    z_new = -sin_theta * x + cos_theta * z
    return [x_new, y, z_new]
  elsif axis == 'z'
    cos_theta = Math.cos(angle)
    sin_theta = Math.sin(angle)
    x_new = cos_theta * x - sin_theta * y
    y_new = sin_theta * x + cos_theta * y
    return [x_new, y_new, z]
  end
end

def translate_point(x, y, z, dx, dy, dz)
  return [x + dx, y + dy, z + dz]
end

def apply_transformations(points, rotations, translations)
  transformed_points = []
  points.each do |point|
    x, y, z = point
    rotations.each do |rotation|
      x, y, z = rotate_point(x, y, z, *rotation)
    end
    translations.each do |translation|
      x, y, z = translate_point(x, y, z, *translation)
    end
    transformed_points << [x, y, z]
  end
  return transformed_points
end

def main
  points = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
  rotations = [Math::PI / 4, 'x'], [Math::PI / 4, 'y']
  translations = [[1, 1, 1]]
  loop do
    points = apply_transformations(points, rotations, translations)
    puts points.inspect
  end
end

main