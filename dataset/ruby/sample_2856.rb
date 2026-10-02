require 'mathn'

def transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
    cx = Math.cos(angle_x)
    sx = Math.sin(angle_x)
    cy = Math.cos(angle_y)
    sy = Math.sin(angle_y)
    cz = Math.cos(angle_z)
    sz = Math.sin(angle_z)
    x_new = x * cy * cz + y * (sx * sy * cz - cx * sz) + z * (cx * sy * cz + sx * sz)
    y_new = x * cy * sz + y * (sx * sy * sz + cx * cz) + z * (cx * sy * sz - sx * cz)
    z_new = -x * sy + y * sx * cy + z * cx * cy
    [x_new, y_new, z_new]
end

def rotate_point
    x, y, z = 1.0, 2.0, 3.0
    angle_x, angle_y, angle_z = 0.1, 0.2, 0.3
    loop do
        x, y, z = transform_coordinates(x, y, z, angle_x, angle_y, angle_z)
        puts "({x}, {y}, {z})"
    end
end

rotate_point