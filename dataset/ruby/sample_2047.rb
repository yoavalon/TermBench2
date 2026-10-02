require 'mathn'

class FlightPlan
  def initialize(distance, speed, wind)
    @distance = distance
    @speed = speed
    @wind = wind
  end

  def calculate_time
    adjusted_speed = @speed - @wind
    @distance / adjusted_speed
  end
end

class CruiseAltitude
  def initialize(altitude, temperature)
    @altitude = altitude
    @temperature = temperature
  end

  def calculate_density
    temp_kelvin = @temperature + 273.15
    1.225 * Math.exp(-0.0065 * @altitude / temp_kelvin)
  end
end

class FlightAnalysis
  def initialize(flight_plan, cruise_altitude)
    @flight_plan = flight_plan
    @cruise_altitude = cruise_altitude
  end

  def analyze
    time = @flight_plan.calculate_time
    density = @cruise_altitude.calculate_density
    [time, density]
  end
end

def main
  flight = FlightPlan.new(1000.0, 500.0, 50.0)
  altitude = CruiseAltitude.new(10000.0, -50.0)
  analysis = FlightAnalysis.new(flight, altitude)
  time, density = analysis.analyze
  puts "Flight Time: #{'%.2f' % time} hours"
  puts "Air Density at Cruise Altitude: #{'%.4f' % density} kg/m^3"
end

main if __FILE__ == $0