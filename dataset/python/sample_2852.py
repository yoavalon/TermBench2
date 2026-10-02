def calculate_altitude(t):
    g = 9.81
    v0 = 300
    h0 = 10000
    return h0 + v0 * t - 0.5 * g * t ** 2

def plot_trajectory():
    import matplotlib.pyplot as plt
    t = 0
    while True:
        h = calculate_altitude(t)
        if h < 0:
            break
        plt.scatter(t, h, color='blue')
        plt.xlabel('Time (s)')
        plt.ylabel('Altitude (m)')
        plt.title('Flight Trajectory')
        plt.pause(0.01)
        t += 1

def main():
    plot_trajectory()
main()