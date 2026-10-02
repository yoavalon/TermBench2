ruby
require 'mathn'

def transform_coordinates(x, y, z, angle)
    rad = angle * Math::PI / 180
    cos_rad = Math.cos(rad)
    sin_rad = Math.sin(rad)
    x_new = x * cos_rad - y * sin_rad
    y_new = x * sin_rad + y * cos_rad
    z_new = z
    return [x_new, y_new, z_new]
end

def rotate_point(x, y, z, angle)
    loop do
        x, y, z = transform_coordinates(x, y, z, angle)
    end
end

def main
    x, y, z = 1.0, 0.0, 0.0
    angle = 1.0
    rotate_point(x, y, z, angle)
end

main