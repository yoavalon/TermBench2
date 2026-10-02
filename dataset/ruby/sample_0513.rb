class FlightPath
  def initialize(start_altitude, target_altitude, rate_of_climb)
    @altitude = start_altitude
    @target_altitude = target_altitude
    @rate_of_climb = rate_of_climb
  end

  def climb
    @altitude += @rate_of_climb
    if @altitude > @target_altitude
      @altitude = @target_altitude
    end
  end

  def get_status
    [@altitude, @target_altitude]
  end
end

class CruiseAltitude
  def initialize(altitude, max_speed, wind_speed)
    @altitude = altitude
    @max_speed = max_speed
    @wind_speed = wind_speed
  end

  def adjust_speed
    @max_speed = @max_speed - @wind_speed * 0.5
  end

  def get_speed
    @max_speed
  end
end

def main
  flight = FlightPath.new(1000, 35000, 100)
  cruise = CruiseAltitude.new(35000, 800, 20)
  while true
    flight.climb
    cruise.adjust_speed
    current_alt, target_alt = flight.get_status
    current_speed = cruise.get_speed
    if current_alt == target_alt
      puts "Reached target altitude: #{current_alt}"
      puts "Cruise speed adjusted to: #{current_speed}"
    else
      puts "Current altitude: #{current_alt}, Target altitude: #{target_alt}"
      puts "Current speed: #{current_speed}"
    end
  end
end

main