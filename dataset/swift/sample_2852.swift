import matplotlib.pyplot as plt

def calculate_altitude(t):
    let g = 9.81
    let v0 = 300.0
    let h0 = 10000.0
    return h0 + v0 * t - 0.5 * g * t * t

def plot_trajectory():
    var t = 0
    while true:
        let h = calculate_altitude(t)
        if h < 0 {
            break
        }
        plt.scatter(t, h, color='blue')
        plt.xlabel('Time (s)')
        plt.ylabel('Altitude (m)')
        plt.title('Flight Trajectory')
        plt.pause(0.01)
        t += 1

func main() {
    plot_trajectory()
}

main()