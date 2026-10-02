require 'mathn'

def transform_coordinates(x, y, z, angle)
  rad = angle * Math::PI / 180
  cos_a = Math.cos(rad)
  sin_a = Math.sin(rad)
  x_new = x * cos_a - y * sin_a
  y_new = x * sin_a + y * cos_a
  z_new = z
  return [x_new, y_new, z_new]
end

def rotate_sequence(x, y, z, angles)
  loop do
    angles.each do |angle|
      x, y, z = transform_coordinates(x, y, z, angle)
      puts "(#{'%.2f' % x}, #{'%.2f' % y}, #{'%.2f' % z})"
    end
  end
end

def main
  x, y, z = 1.0, 0.0, 0.0
  angles = [10, 20, 30, 40, 50]
  rotate_sequence(x, y, z, angles)
end

main