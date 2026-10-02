class FlightData

  def initialize(altitude, speed, distance, max_altitude)
    @altitude = altitude
    @speed = speed
    @distance = distance
    @max_altitude = max_altitude
  end

  def update_altitude(new_altitude)
    if new_altitude <= @max_altitude
      @altitude = new_altitude
    else
      @altitude = @max_altitude
    end
  end

  def update_distance(new_distance)
    @distance = new_distance
  end

end

class CruisePlanner

  def initialize(flight_data)
    @flight_data = flight_data
  end

  def calculate_cruise_altitude
    if @flight_data.speed > 500
      [@flight_data.altitude + 1000, @flight_data.max_altitude].min
    else
      [@flight_data.altitude - 1000, 0].max
    end
  end

  def adjust_trajectory
    new_altitude = calculate_cruise_altitude
    @flight_data.update_altitude(new_altitude)
    @flight_data.update_distance(@flight_data.distance + 100)
  end

end

def main
  flight_data = FlightData.new(5000, 600, 0, 10000)
  cruise_planner = CruisePlanner.new(flight_data)
  10.times do
    cruise_planner.adjust_trajectory
  end
  puts "Final Altitude: #{flight_data.altitude}"
  puts "Final Distance: #{flight_data.distance}"
end

main