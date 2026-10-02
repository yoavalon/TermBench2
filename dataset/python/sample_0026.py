def boundary_conditions(x, lb, ub):
    for i in range(len(x)):
        if x[i] < lb[i]:
            x[i] = lb[i]
        elif x[i] > ub[i]:
            x[i] = ub[i]
    return x

def main():
    x = [1.5, -2.0, 3.0]
    lb = [0.0, -1.0, 2.0]
    ub = [2.0, 0.0, 4.0]
    result = boundary_conditions(x, lb, ub)
    print(result)
main()