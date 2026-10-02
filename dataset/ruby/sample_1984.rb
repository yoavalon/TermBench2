require 'mathn'

def transform_coordinates(x, y, z, angle)
    rad = angle * Math::PI / 180
    cos_a = Math.cos(rad)
    sin_a = Math.sin(rad)
    new_x = x * cos_a - y * sin_a
    new_y = x * sin_a + y * cos_a
    new_z = z
    [new_x, new_y, new_z]
end

def calculate_distance(x1, y1, z1, x2, y2, z2)
    Math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2 + (z2 - z1) ** 2)
end

def main
    x, y, z = 1.0, 2.0, 3.0
    angle = 30
    x_t, y_t, z_t = transform_coordinates(x, y, z, angle)
    d = calculate_distance(x, y, z, x_t, y_t, z_t)
    puts "Transformed Coordinates: (#{x_t}, #{y_t}, #{z_t})"
    puts "Distance: #{d}"
end

main