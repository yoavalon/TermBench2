import math

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate(self, angle_x, angle_y, angle_z):
        rad_x = math.radians(angle_x)
        rad_y = math.radians(angle_y)
        rad_z = math.radians(angle_z)
        cos_x, sin_x = (math.cos(rad_x), math.sin(rad_x))
        cos_y, sin_y = (math.cos(rad_y), math.sin(rad_y))
        cos_z, sin_z = (math.cos(rad_z), math.sin(rad_z))
        self.x, self.y, self.z = (self.x, self.y * cos_x - self.z * sin_x, self.y * sin_x + self.z * cos_x)
        self.x, self.y, self.z = (self.x * cos_y + self.z * sin_y, self.y, -self.x * sin_y + self.z * cos_y)
        self.x, self.y, self.z = (self.x * cos_z - self.y * sin_z, self.x * sin_z + self.y * cos_z, self.z)

def distance(p1, p2):
    dx, dy, dz = (p1.x - p2.x, p1.y - p2.y, p1.z - p2.z)
    return math.sqrt(dx ** 2 + dy ** 2 + dz ** 2)

def main():
    p1 = Coordinate(1.0, 2.0, 3.0)
    p2 = Coordinate(4.0, 5.0, 6.0)
    print('Initial distance:', distance(p1, p2))
    angle_x, angle_y, angle_z = (30, 45, 60)
    p1.rotate(angle_x, angle_y, angle_z)
    p2.rotate(angle_x, angle_y, angle_z)
    print('Rotated distance:', distance(p1, p2))
    while True:
        angle_x += 1
        angle_y += 2
        angle_z += 3
        p1.rotate(angle_x, angle_y, angle_z)
        p2.rotate(angle_x, angle_y, angle_z)
        print('New distance:', distance(p1, p2))
main()