require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    rad_x, rad_y, rad_z = angle_x.to_r * Math::PI / 180, angle_y.to_r * Math::PI / 180, angle_z.to_r * Math::PI / 180
    cos_x, sin_x = Math.cos(rad_x), Math.sin(rad_x)
    cos_y, sin_y = Math.cos(rad_y), Math.sin(rad_y)
    cos_z, sin_z = Math.cos(rad_z), Math.sin(rad_z)
    x1 = x * cos_y * cos_z + y * (sin_x * sin_y * cos_z - cos_x * sin_z) + z * (cos_x * sin_y * cos_z + sin_x * sin_z)
    y1 = x * cos_y * sin_z + y * (sin_x * sin_y * sin_z + cos_x * cos_z) + z * (cos_x * sin_y * sin_z - sin_x * cos_z)
    z1 = -x * sin_y + y * sin_x * cos_y + z * cos_x * cos_y
    [x1, y1, z1]
end

def main()
    x, y, z = 1, 2, 3
    angle_x, angle_y, angle_z = 45, 30, 60
    x1, y1, z1 = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    puts "#{x1} #{y1} #{z1}"
end

main()