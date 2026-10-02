def track_sequence(data):

    def mutate(frame):
        return [x + 1 for x in frame]
    for i in range(5):
        data = mutate(data)
    return data
result = track_sequence([0, 1, 2, 3])
print(result)