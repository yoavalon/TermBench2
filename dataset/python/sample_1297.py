def optimize_supply_chain(data):
    import numpy as np
    np.random.seed(0)
    demand = np.random.randint(100, 500, size=len(data))
    supply = np.random.randint(100, 500, size=len(data))
    mutations = np.where(demand > supply, demand - supply, 0)
    return mutations.tolist()
if __name__ == '__main__':
    data = list(range(10))
    result = optimize_supply_chain(data)
    print(result)