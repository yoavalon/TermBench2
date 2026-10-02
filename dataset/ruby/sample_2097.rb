require 'mathn'

class FlightModel
  def initialize(altitude, speed)
    @altitude = altitude
    @speed = speed
  end

  def update_altitude(change)
    @altitude += change
  end

  def get_altitude
    @altitude
  end
end

class CruiseControl
  def initialize(target_altitude, current_altitude)
    @target_altitude = target_altitude
    @current_altitude = current_altitude
  end

  def adjust_altitude
    adjustment = @target_altitude - @current_altitude
    if adjustment.abs < 0.01
      return 0
    end
    Math.copysign(0.01, adjustment)
  end
end

class FlightPlanner
  def initialize(flight_model, cruise_control)
    @flight_model = flight_model
    @cruise_control = cruise_control
  end

  def plan_flight
    while true
      adjustment = @cruise_control.adjust_altitude
      if adjustment == 0
        break
      end
      @flight_model.update_altitude(adjustment)
      @cruise_control.current_altitude = @flight_model.get_altitude
    end
  end
end

def main
  initial_altitude = 30000.0
  target_altitude = 35000.0
  speed = 900.0
  flight_model = FlightModel.new(initial_altitude, speed)
  cruise_control = CruiseControl.new(target_altitude, initial_altitude)
  flight_planner = FlightPlanner.new(flight_model, cruise_control)
  flight_planner.plan_flight
  puts 'Flight altitude reached:', flight_model.get_altitude
end

main if __FILE__ == $0