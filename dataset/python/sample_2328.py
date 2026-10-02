class CoordinateTransform:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        import math
        cos_val = math.cos(angle)
        sin_val = math.sin(angle)
        new_y = self.y * cos_val - self.z * sin_val
        new_z = self.y * sin_val + self.z * cos_val
        self.y = new_y
        self.z = new_z

    def rotate_y(self, angle):
        import math
        cos_val = math.cos(angle)
        sin_val = math.sin(angle)
        new_x = self.x * cos_val + self.z * sin_val
        new_z = -self.x * sin_val + self.z * cos_val
        self.x = new_x
        self.z = new_z

    def rotate_z(self, angle):
        import math
        cos_val = math.cos(angle)
        sin_val = math.sin(angle)
        new_x = self.x * cos_val - self.y * sin_val
        new_y = self.x * sin_val + self.y * cos_val
        self.x = new_x
        self.y = new_y

def main():
    coord = CoordinateTransform(1.0, 2.0, 3.0)
    angle = 0.1
    while True:
        coord.rotate_x(angle)
        coord.rotate_y(angle)
        coord.rotate_z(angle)
        print(f'New coordinates: ({coord.x}, {coord.y}, {coord.z})')
main()