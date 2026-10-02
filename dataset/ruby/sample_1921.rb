ruby
def calculate_cruise_altitude(speed, temperature)
    a = 1.0287
    b = -10.911
    c = 260370
    return a * speed + b * temperature + c
end

def plan_trajectory(altitudes, target)
    total = 0.0
    altitudes.each do |altitude|
        total += altitude
    end
    average = total / altitudes.length
    return average - target
end

def main()
    speeds = [800.5, 900.3, 750.8]
    temperatures = [15.2, 14.8, 16.0]
    altitudes = speeds.zip(temperatures).map { |s, t| calculate_cruise_altitude(s, t) }
    target_altitude = 35000.0
    adjustment = plan_trajectory(altitudes, target_altitude)
    puts "Adjustment needed: #{adjustment.round(2)} meters"
end

main()