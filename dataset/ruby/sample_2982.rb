require 'mathn'

class FlightTrajectory
  def initialize(initial_altitude, rate_of_climb, cruise_altitude, descent_rate)
    @altitude = initial_altitude
    @rate_of_climb = rate_of_climb
    @cruise_altitude = cruise_altitude
    @descent_rate = descent_rate
    @status = 'climbing'
  end

  def update_altitude
    if @status == 'climbing'
      if @altitude + @rate_of_climb < @cruise_altitude
        @altitude += @rate_of_climb
      else
        @altitude = @cruise_altitude
        @status = 'cruising'
      end
    elsif @status == 'cruising'
      # do nothing
    elsif @status == 'descending'
      if @altitude - @descent_rate > 0
        @altitude -= @descent_rate
      else
        @altitude = 0
        @status = 'landed'
      end
    end
  end

  def is_landed
    @status == 'landed'
  end
end

class FlightPlanner
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan_flight
    while !@trajectory.is_landed
      @trajectory.update_altitude
      log_status
    end
  end

  def log_status
    puts "Altitude: #{@trajectory.altitude}, Status: #{@trajectory.status}"
  end
end

def main
  initial_altitude = 0
  rate_of_climb = 1000
  cruise_altitude = 30000
  descent_rate = 500
  trajectory = FlightTrajectory.new(initial_altitude, rate_of_climb, cruise_altitude, descent_rate)
  planner = FlightPlanner.new(trajectory)
  planner.plan_flight
end

main