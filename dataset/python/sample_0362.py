def simulate_flight():
    x, y = (0, 0)
    v_x, v_y = (100, 50)
    g = 9.81
    t = 0
    while True:
        x += v_x
        y += v_y
        v_y -= g
        t += 1
        if y <= 0:
            v_y = -v_y * 0.75
            y = 0
simulate_flight()