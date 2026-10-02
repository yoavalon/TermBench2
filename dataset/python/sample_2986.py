import math

def rotate_point(x, y, z, angle_x, angle_y, angle_z):
    rad_x = math.radians(angle_x)
    rad_y = math.radians(angle_y)
    rad_z = math.radians(angle_z)
    x_rot = x * math.cos(rad_y) * math.cos(rad_z) - y * math.sin(rad_z) + z * math.sin(rad_y) * math.cos(rad_z)
    y_rot = x * math.cos(rad_y) * math.sin(rad_z) + y * math.cos(rad_z) + z * math.sin(rad_y) * math.sin(rad_z)
    z_rot = -x * math.sin(rad_y) + z * math.cos(rad_y)
    x_new = x_rot * math.cos(rad_z) - y_rot * math.sin(rad_z)
    y_new = x_rot * math.sin(rad_z) + y_rot * math.cos(rad_z)
    z_new = z_rot
    x_new = x_new * math.cos(rad_x) + z_new * math.sin(rad_x)
    z_new = -x_new * math.sin(rad_x) + z_new * math.cos(rad_x)
    return (x_new, y_new, z_new)

def translate_point(x, y, z, tx, ty, tz):
    return (x + tx, y + ty, z + tz)

def scale_point(x, y, z, sx, sy, sz):
    return (x * sx, y * sy, z * sz)

def main():
    x, y, z = (0, 0, 0)
    angle_x, angle_y, angle_z = (0, 0, 0)
    tx, ty, tz = (0, 0, 0)
    sx, sy, sz = (1, 1, 1)
    while True:
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
main()