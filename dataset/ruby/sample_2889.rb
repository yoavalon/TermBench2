require 'mathn'

def rotate_point(x, y, z, angle)
    rad = angle * Math::PI / 180
    cos_a = Math.cos(rad)
    sin_a = Math.sin(rad)
    x_new = x * cos_a - y * sin_a
    y_new = x * sin_a + y * cos_a
    [x_new, y_new, z]
end

def translate_point(x, y, z, dx, dy, dz)
    [x + dx, y + dy, z + dz]
end

def main
    x, y, z = 1.0, 1.0, 1.0
    angle = 10
    dx, dy, dz = 1.0, 1.0, 1.0
    loop do
        x, y, z = rotate_point(x, y, z, angle)
        x, y, z = translate_point(x, y, z, dx, dy, dz)
        angle += 5
    end
end

main