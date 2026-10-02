def optimize_logistics(data):
    seq, total, cap = ([], 0, 50)
    for item in data:
        if total + item <= cap:
            seq.append(item)
            total += item
        else:
            break
    return seq
if __name__ == '__main__':
    data = [10, 20, 30, 40, 50, 60]
    result = optimize_logistics(data)
    print(result)