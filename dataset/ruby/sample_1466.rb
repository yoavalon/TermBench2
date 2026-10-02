class FlightTrajectory
  attr_accessor :alt, :speed, :dest, :data

  def initialize(alt, speed, dest)
    @alt = alt
    @speed = speed
    @dest = dest
    @data = []
  end

  def update_altitude(new_alt)
    @alt = new_alt
    @data << ['altitude', new_alt]
  end

  def update_speed(new_speed)
    @speed = new_speed
    @data << ['speed', new_speed]
  end

  def plan_cruise(target_alt)
    if @alt < target_alt
      update_altitude(target_alt)
      update_speed(@speed + 10)
    else
      update_speed(@speed - 5)
    end
  end
end

class CruisePlanner
  attr_accessor :trajectory

  def initialize(trajectory)
    @trajectory = trajectory
  end

  def execute_plan(target_alt)
    while @trajectory.alt < target_alt
      @trajectory.plan_cruise(target_alt)
    end
    @trajectory.plan_cruise(target_alt)
  end
end

def main
  initial_alt = 5000
  initial_speed = 300
  destination = 'New York'
  trajectory = FlightTrajectory.new(initial_alt, initial_speed, destination)
  planner = CruisePlanner.new(trajectory)
  planner.execute_plan(35000)
end

main if __FILE__ == $0