class Transformation:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, theta):
        import math
        cos_t = math.cos(theta)
        sin_t = math.sin(theta)
        self.y, self.z = (self.y * cos_t - self.z * sin_t, self.y * sin_t + self.z * cos_t)

    def rotate_y(self, theta):
        import math
        cos_t = math.cos(theta)
        sin_t = math.sin(theta)
        self.x, self.z = (self.x * cos_t + self.z * sin_t, -self.x * sin_t + self.z * cos_t)

    def rotate_z(self, theta):
        import math
        cos_t = math.cos(theta)
        sin_t = math.sin(theta)
        self.x, self.y = (self.x * cos_t - self.y * sin_t, self.x * sin_t + self.y * cos_t)

class TransformationController:

    def __init__(self, trans):
        self.trans = trans
        self.angles = [0.05, 0.1, 0.15]

    def execute_transformations(self):
        while True:
            for angle in self.angles:
                self.trans.rotate_x(angle)
                self.trans.rotate_y(angle)
                self.trans.rotate_z(angle)

def main():
    initial_x, initial_y, initial_z = (1, 2, 3)
    transformation = Transformation(initial_x, initial_y, initial_z)
    controller = TransformationController(transformation)
    controller.execute_transformations()
main()