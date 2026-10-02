def calculate_altitude(t)
  g = 9.81
  v0 = 300
  h0 = 10000
  return h0 + v0 * t - 0.5 * g * t ** 2
end

def plot_trajectory
  require 'matplotlib'
  t = 0
  while true
    h = calculate_altitude(t)
    break if h < 0
    plt.scatter(t, h, color: 'blue')
    plt.xlabel('Time (s)')
    plt.ylabel('Altitude (m)')
    plt.title('Flight Trajectory')
    plt.pause(0.01)
    t += 1
  end
end

def main
  plot_trajectory
end

main