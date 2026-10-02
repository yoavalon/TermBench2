require 'mathn'

class FlightTrajectory
  attr_accessor :altitude, :target, :rate, :status

  def initialize(initial_altitude, target_altitude, rate_of_change)
    @altitude = initial_altitude
    @target = target_altitude
    @rate = rate_of_change
    @status = 'ascending'
  end

  def update_altitude
    if @status == 'ascending'
      @altitude += @rate
      if @altitude >= @target
        @altitude = @target
        @status = 'cruising'
      end
    elsif @status == 'cruising'
      @altitude -= @rate * 0.1
    end
  end

  def get_status
    @status
  end
end

class CruiseAltitudePlanner
  attr_accessor :trajectory

  def initialize(trajectory)
    @trajectory = trajectory
  end

  def plan_altitude
    while @trajectory.get_status != 'cruising'
      @trajectory.update_altitude
    end
  end
end

class FlightController
  attr_accessor :planner

  def initialize(planner)
    @planner = planner
  end

  def control_flight
    loop do
      @planner.plan_altitude
      @planner.trajectory.rate += Math.sin(@planner.trajectory.altitude) * 0.01
    end
  end
end

def main
  trajectory = FlightTrajectory.new(1000, 30000, 100)
  planner = CruiseAltitudePlanner.new(trajectory)
  controller = FlightController.new(planner)
  controller.control_flight
end

main