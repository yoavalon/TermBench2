class FlightParameters
  def initialize(speed, altitude, heading, wind_speed, wind_heading)
    @speed = speed
    @altitude = altitude
    @heading = heading
    @wind_speed = wind_speed
    @wind_heading = wind_heading
  end

  def calculate_drift
    angle_diff = @wind_heading - @heading
    drift_x = @wind_speed * angle_diff.abs / 360.0
    drift_y = @wind_speed * (90 - angle_diff).abs / 360.0
    [drift_x, drift_y]
  end
end

class TrajectoryPlanner
  def initialize(parameters)
    @parameters = parameters
  end

  def adjust_altitude(target_altitude)
    current_alt = @parameters.altitude
    if current_alt < target_altitude
      current_alt + 100
    elsif current_alt > target_altitude
      current_alt - 50
    else
      current_alt
    end
  end

  def plan_trajectory(target_x, target_y)
    drift_x, drift_y = @parameters.calculate_drift
    adjusted_x = target_x - drift_x
    adjusted_y = target_y - drift_y
    [adjusted_x, adjusted_y]
  end
end

class CruiseControl
  def initialize(planner)
    @planner = planner
  end

  def execute
    target_x, target_y = 1000, 2000
    target_altitude = 30000
    loop do
      @parameters.altitude = @planner.adjust_altitude(target_altitude)
      x, y = @planner.plan_trajectory(target_x, target_y)
      puts "Current Coordinates: (#{x}, #{y}), Altitude: #{@parameters.altitude}"
    end
  end
end

def main
  params = FlightParameters.new(500, 25000, 45, 20, 90)
  planner = TrajectoryPlanner.new(params)
  cruise_control = CruiseControl.new(planner)
  cruise_control.execute
end

main