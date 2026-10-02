def sequence_tracker(max_iter, boundary):
    result = []
    i = 0
    while i < max_iter and len(result) < boundary:
        result.append(i)
        i += 1
    return result
sequence_tracker(10, 5)