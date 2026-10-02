def flight_planner():
    data = [5000, 6000, 7000, 8000, 9000]
    index = 0
    while index < len(data):
        if data[index] > 7500:
            data[index] -= 500
        index += 1
    return data
if __name__ == '__main__':
    flight_planner()