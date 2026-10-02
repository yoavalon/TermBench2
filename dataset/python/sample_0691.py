def consensus(state, threshold, depth):
    if depth == 0 or sum(state) >= threshold:
        return state
    else:
        return consensus([x + 1 if x < threshold else x for x in state], threshold, depth - 1)
consensus([0, 0, 0], 5, 3)