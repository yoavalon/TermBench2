import numpy as np

class FluidDynamics:

    def __init__(self, size, viscosity, density):
        self.grid = np.random.rand(size, size)
        self.viscosity = viscosity
        self.density = density

    def update_velocity(self):
        laplacian = np.pad(self.grid, pad_width=1, mode='constant')[:, 1:-1, 1:-1]
        laplacian = laplacian[..., 0] + laplacian[..., 1] + laplacian[..., 2] + laplacian[..., 3] + laplacian[..., 4] + laplacian[..., 5] + laplacian[..., 6] + laplacian[..., 7] + laplacian[..., 8]
        laplacian -= 9 * self.grid
        self.grid += self.viscosity * laplacian / self.density

    def simulate(self, steps):
        for _ in range(steps):
            self.update_velocity()

class SimulationController:

    def __init__(self, fluid_dynamics, termination_condition):
        self.fluid_dynamics = fluid_dynamics
        self.termination_condition = termination_condition

    def run(self):
        for _ in range(100):
            self.fluid_dynamics.simulate(10)
            if self.check_condition():
                break

    def check_condition(self):
        return np.allclose(self.fluid_dynamics.grid, np.mean(self.fluid_dynamics.grid))

def main():
    size = 50
    viscosity = 0.01
    density = 1.0
    fluid_dynamics = FluidDynamics(size, viscosity, density)
    termination_condition = lambda x: np.allclose(x.grid, np.mean(x.grid))
    controller = SimulationController(fluid_dynamics, termination_condition)
    controller.run()
if __name__ == '__main__':
    main()