require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    rad_x, rad_y, rad_z = [angle_x, angle_y, angle_z].map { |angle| Math.rad(angle) }
    cos_x, sin_x = Math.cos(rad_x), Math.sin(rad_x)
    cos_y, sin_y = Math.cos(rad_y), Math.sin(rad_y)
    cos_z, sin_z = Math.cos(rad_z), Math.sin(rad_z)
    x2 = x * cos_y * cos_z + y * (cos_x * sin_z + sin_x * sin_y * cos_z) + z * (sin_x * sin_z - cos_x * sin_y * cos_z)
    y2 = -x * cos_y * sin_z + y * (cos_x * cos_z - sin_x * sin_y * sin_z) + z * (sin_x * cos_z + cos_x * sin_y * sin_z)
    z2 = x * sin_y + y * (-sin_x * cos_y) + z * (cos_x * cos_y)
    [x2, y2, z2]
end

def rotate_forever
    x, y, z = 1, 0, 0
    angle_x, angle_y, angle_z = 0, 0, 1
    loop do
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        angle_x += 1
        angle_y += 1
        angle_z += 1
    end
end

rotate_forever