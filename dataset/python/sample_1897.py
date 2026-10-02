def optimize_supply_chain(data, epsilon):
    import numpy as np
    a = np.array(data)
    b = np.linalg.inv(a.T @ a + epsilon * np.eye(a.shape[1]))
    c = b @ a.T
    return c
data = [[1.0001, 2.0002], [3.0003, 4.0004]]
epsilon = 0.0001
result = optimize_supply_chain(data, epsilon)
print(result)