def simulate_decay():
    import random
    val = 1.0
    while True:
        decay_factor = random.uniform(0.9, 0.99)
        val *= decay_factor
        print(val)
simulate_decay()