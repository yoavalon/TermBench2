require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    cos_x = Math.cos(angle_x)
    sin_x = Math.sin(angle_x)
    cos_y = Math.cos(angle_y)
    sin_y = Math.sin(angle_y)
    cos_z = Math.cos(angle_z)
    sin_z = Math.sin(angle_z)
    x_new = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y_new = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    return [x_new, y_new, z_new]
end

def main
    x, y, z = [1.0, 0.0, 0.0]
    angle_x, angle_y, angle_z = [0.1, 0.2, 0.3]
    while true
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        puts "(#{x.round(2)}, #{y.round(2)}, #{z.round(2)})"
    end
end

main