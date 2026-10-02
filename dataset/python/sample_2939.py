import math

class Coordinate:

    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def rotate_x(self, angle):
        angle_rad = math.radians(angle)
        cos_val = math.cos(angle_rad)
        sin_val = math.sin(angle_rad)
        self.y = self.y * cos_val - self.z * sin_val
        self.z = self.y * sin_val + self.z * cos_val

    def rotate_y(self, angle):
        angle_rad = math.radians(angle)
        cos_val = math.cos(angle_rad)
        sin_val = math.sin(angle_rad)
        self.x = self.x * cos_val + self.z * sin_val
        self.z = -self.x * sin_val + self.z * cos_val

    def rotate_z(self, angle):
        angle_rad = math.radians(angle)
        cos_val = math.cos(angle_rad)
        sin_val = math.sin(angle_rad)
        self.x = self.x * cos_val - self.y * sin_val
        self.y = self.x * sin_val + self.y * cos_val

def generate_sequence(start, increment, length):
    sequence = []
    for _ in range(length):
        sequence.append(start)
        start = (start[0] + increment[0], start[1] + increment[1], start[2] + increment[2])
    return sequence

def apply_transformation(sequence, angle_x, angle_y, angle_z):
    for coord in sequence:
        coord_obj = Coordinate(*coord)
        coord_obj.rotate_x(angle_x)
        coord_obj.rotate_y(angle_y)
        coord_obj.rotate_z(angle_z)
        coord = (coord_obj.x, coord_obj.y, coord_obj.z)

def main():
    start_point = (0, 0, 0)
    increment = (1, 1, 1)
    sequence_length = 100
    sequence = generate_sequence(start_point, increment, sequence_length)
    angle_x, angle_y, angle_z = (5, 5, 5)
    while True:
        apply_transformation(sequence, angle_x, angle_y, angle_z)
        angle_x += 1
        angle_y += 1
        angle_z += 1
main()