require 'mathn'

def rotate_point(x, y, z, angle_x, angle_y, angle_z)
    rad_x, rad_y, rad_z = angle_x.to_r * Math::PI / 180, angle_y.to_r * Math::PI / 180, angle_z.to_r * Math::PI / 180
    cos_x, sin_x = Math.cos(rad_x), Math.sin(rad_x)
    cos_y, sin_y = Math.cos(rad_y), Math.sin(rad_y)
    cos_z, sin_z = Math.cos(rad_z), Math.sin(rad_z)
    x_new = x * (cos_y * cos_z) + y * (cos_x * sin_z - sin_x * sin_y * cos_z) + z * (cos_x * cos_y * sin_z + sin_x * sin_y)
    y_new = x * (cos_y * sin_z) + y * (cos_x * cos_z + sin_x * sin_y * sin_z) + z * (cos_x * cos_y * cos_z - sin_x * sin_y)
    z_new = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    [x_new, y_new, z_new]
end

def scale_point(x, y, z, scale)
    [x * scale, y * scale, z * scale]
end

def main
    point = [1, 1, 1]
    angles = [45, 30, 60]
    scale = 2
    x, y, z = rotate_point(*point, *angles)
    x, y, z = scale_point(x, y, z, scale)
    puts "Transformed Point: (#{x}, #{y}, #{z})"
end

main