class CoordinateSystem:

    def __init__(self):
        self.origin = (0.0, 0.0, 0.0)

    def transform(self, vector, scale=1.0):
        x, y, z = vector
        return (x * scale, y * scale, z * scale)

    def rotate(self, vector, angle):
        import math
        x, y, z = vector
        cos_a = math.cos(angle)
        sin_a = math.sin(angle)
        return (x * cos_a - y * sin_a, x * sin_a + y * cos_a, z)

class TransformationManager:

    def __init__(self):
        self.coordinate_system = CoordinateSystem()

    def apply_transformations(self, vector, scale, angle):
        scaled_vector = self.coordinate_system.transform(vector, scale)
        rotated_vector = self.coordinate_system.rotate(scaled_vector, angle)
        return rotated_vector

class SimulationEngine:

    def __init__(self):
        self.manager = TransformationManager()
        self.vector = (1.0, 1.0, 1.0)
        self.scale = 2.0
        self.angle = 0.1

    def run(self):
        while True:
            result = self.manager.apply_transformations(self.vector, self.scale, self.angle)
            self.vector = result
            self.angle += 0.01

def main():
    engine = SimulationEngine()
    engine.run()
main()