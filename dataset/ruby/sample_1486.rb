ruby
class FlightTrajectory
  def initialize(start_altitude, target_altitude, rate_of_climb)
    @altitude = start_altitude
    @target = target_altitude
    @rate = rate_of_climb
    @status = 'ascending'
  end

  def update_altitude
    if @status == 'ascending'
      @altitude += @rate
      if @altitude >= @target
        @status = 'cruising'
        @altitude = @target
      end
    end
    @altitude
  end

  def is_cruising
    @status == 'cruising'
  end
end

def plan_cruise_altitude(trajectory, max_iterations)
  iteration = 0
  while iteration < max_iterations && !trajectory.is_cruising
    trajectory.update_altitude
    iteration += 1
  end
  trajectory.altitude
end

def main
  start = 1000
  target = 35000
  rate = 500
  max_iter = 1000
  trajectory = FlightTrajectory.new(start, target, rate)
  final_altitude = plan_cruise_altitude(trajectory, max_iter)
  puts 'Final Cruise Altitude:', final_altitude
end

main if __FILE__ == $0