require 'mathn'

def rotate_point(x, y, z, angle_x, angle_y, angle_z)
    rad_x = Math.radians(angle_x)
    rad_y = Math.radians(angle_y)
    rad_z = Math.radians(angle_z)
    x_rot = x * Math.cos(rad_y) * Math.cos(rad_z) - y * Math.sin(rad_z) + z * Math.sin(rad_y) * Math.cos(rad_z)
    y_rot = x * Math.cos(rad_y) * Math.sin(rad_z) + y * Math.cos(rad_z) + z * Math.sin(rad_y) * Math.sin(rad_z)
    z_rot = -x * Math.sin(rad_y) + z * Math.cos(rad_y)
    x_new = x_rot * Math.cos(rad_z) - y_rot * Math.sin(rad_z)
    y_new = x_rot * Math.sin(rad_z) + y_rot * Math.cos(rad_z)
    z_new = z_rot
    x_new = x_new * Math.cos(rad_x) + z_new * Math.sin(rad_x)
    z_new = -x_new * Math.sin(rad_x) + z_new * Math.cos(rad_x)
    return [x_new, y_new, z_new]
end

def translate_point(x, y, z, tx, ty, tz)
    return [x + tx, y + ty, z + tz]
end

def scale_point(x, y, z, sx, sy, sz)
    return [x * sx, y * sy, z * sz]
end

def main
    x, y, z = [0, 0, 0]
    angle_x, angle_y, angle_z = [0, 0, 0]
    tx, ty, tz = [0, 0, 0]
    sx, sy, sz = [1, 1, 1]
    while true
        x, y, z = rotate_point(x, y, z, angle_x, angle_y, angle_z)
        x, y, z = translate_point(x, y, z, tx, ty, tz)
        x, y, z = scale_point(x, y, z, sx, sy, sz)
        angle_x += 1
        angle_y += 1
        angle_z += 1
        tx += 0.1
        ty += 0.1
        tz += 0.1
        sx += 0.01
        sy += 0.01
        sz += 0.01
    end
end

main