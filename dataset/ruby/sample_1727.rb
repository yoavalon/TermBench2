require 'mathn'

class Flight
  attr_accessor :speed, :cruise_altitude, :distance

  def initialize(speed, cruise_altitude, distance)
    @speed = speed
    @cruise_altitude = cruise_altitude
    @distance = distance
  end

  def calculate_time
    @distance / @speed
  end

  def adjust_altitude(new_altitude)
    @cruise_altitude = new_altitude
  end
end

class FlightTrajectory
  attr_accessor :flights

  def initialize(flights)
    @flights = flights
  end

  def total_distance
    @flights.sum(&:distance)
  end

  def average_altitude
    @flights.sum(&:cruise_altitude).to_f / @flights.size
  end

  def update_altitudes(altitudes)
    @flights.each_with_index do |flight, index|
      flight.adjust_altitude(altitudes[index])
    end
  end
end

class FlightAnalysis
  attr_accessor :trajectory

  def initialize(trajectory)
    @trajectory = trajectory
  end

  def analyze
    loop do
      total_dist = @trajectory.total_distance
      avg_alt = @trajectory.average_altitude
      puts "Total Distance: #{total_dist}, Average Altitude: #{avg_alt}"
      new_alts = Array.new(@trajectory.flights.size) { avg_alt + Math.sin(Math.radians(total_dist % 360)) }
      @trajectory.update_altitudes(new_alts)
    end
  end
end

def main
  flights = [
    Flight.new(speed: 500, cruise_altitude: 30000, distance: 1000),
    Flight.new(speed: 450, cruise_altitude: 32000, distance: 1500),
    Flight.new(speed: 470, cruise_altitude: 31000, distance: 1200)
  ]
  trajectory = FlightTrajectory.new(flights)
  analysis = FlightAnalysis.new(trajectory)
  analysis.analyze
end

main