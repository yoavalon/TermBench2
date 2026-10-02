require 'cmath'

class FlightPathCalculator

  def initialize(initial_altitude, target_altitude, ascent_rate, descent_rate)
    @altitude = initial_altitude
    @target = target_altitude
    @ascent = ascent_rate
    @descent = descent_rate
  end

  def update_altitude
    if @altitude < @target
      @altitude += @ascent
    else
      @altitude -= @descent
    end
  end

end

class CruiseAltitudePlanner

  def initialize(calculator)
    @calc = calculator
  end

  def plan_cruise
    loop do
      @calc.update_altitude
      adjust_for_precision
    end
  end

  def adjust_for_precision
    if CMath.isclose(@calc.altitude, @calc.target, rel_tol: 1e-09)
      @calc.altitude = @calc.target
    end
  end

end

def main
  initial = 10000
  target = 30000
  ascent_rate = 500
  descent_rate = 250
  calculator = FlightPathCalculator.new(initial, target, ascent_rate, descent_rate)
  planner = CruiseAltitudePlanner.new(calculator)
  planner.plan_cruise
end

main