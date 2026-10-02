require 'mathn'

class FlightData
  def initialize(altitude, velocity, fuel)
    @altitude = altitude
    @velocity = velocity
    @fuel = fuel
  end
end

class FlightController
  def initialize(flight_data)
    @flight_data = flight_data
  end

  def adjust_altitude
    if @flight_data.altitude < 35000
      @flight_data.altitude += 1000
    else
      @flight_data.altitude -= 1000
    end
  end

  def adjust_velocity
    if @flight_data.velocity < 800
      @flight_data.velocity += 50
    else
      @flight_data.velocity -= 50
    end
  end

  def manage_fuel
    if @flight_data.fuel > 1000
      @flight_data.fuel -= 50
    else
      @flight_data.fuel += 50
    end
  end
end

def simulate_flight
  flight_data = FlightData.new(10000, 700, 5000)
  controller = FlightController.new(flight_data)
  loop do
    controller.adjust_altitude
    controller.adjust_velocity
    controller.manage_fuel
  end
end

def main
  simulate_flight
end

main