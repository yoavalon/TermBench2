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

def apply_transformation(data, angle)
    transformed_data = data.map { |x, y, z| transform_coordinates(x, y, z, angle) }
    return transformed_data
end

def main
    data = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
    angle = 90
    result = apply_transformation(data, angle)
    puts result.inspect
end

main