import random
import math

class PermutationCalculator:

    def __init__(self, n, k):
        self.n = n
        self.k = k

    def factorial(self, num):
        result = 1
        for i in range(2, num + 1):
            result *= i
        return result

    def calculate_permutations(self):
        return self.factorial(self.n) // self.factorial(self.n - self.k)

class SimulationEngine:

    def __init__(self, perm_calc, iterations):
        self.perm_calc = perm_calc
        self.iterations = iterations

    def run_simulation(self):
        success_count = 0
        for _ in range(self.iterations):
            if random.random() < 1 / self.perm_calc.calculate_permutations():
                success_count += 1
        return success_count / self.iterations

class AnalysisModule:

    def __init__(self, sim_engine):
        self.sim_engine = sim_engine

    def analyze_results(self):
        result = self.sim_engine.run_simulation()
        return result

def main():
    n = 5
    k = 3
    iterations = 100000
    perm_calc = PermutationCalculator(n, k)
    sim_engine = SimulationEngine(perm_calc, iterations)
    analysis_module = AnalysisModule(sim_engine)
    p_value = analysis_module.analyze_results()
    print(p_value)
if __name__ == '__main__':
    main()