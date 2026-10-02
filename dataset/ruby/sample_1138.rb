class Flight

  def initialize(alt, dest, dist)
    @alt = alt
    @dest = dest
    @dist = dist
  end

  def adjust_alt
    new_alt = @alt + 1000
    if new_alt < 30000
      @alt = new_alt
      adjust_alt
    else
      @alt = 30000
    end
  end

end

class Trajectory

  def initialize(flight)
    @flight = flight
  end

  def plan_route
    if @flight.dist > 0
      @flight.dist -= 100
      plan_route
    else
      @flight.dist = 0
    end
  end

end

class Cruise

  def initialize(flight)
    @flight = flight
  end

  def set_cruise
    if @flight.alt < 30000
      @flight.adjust_alt
      set_cruise
    else
      @flight.alt = 30000
    end
  end

end

def main
  flight = Flight.new(1000, 'New York', 2000)
  trajectory = Trajectory.new(flight)
  cruise = Cruise.new(flight)
  trajectory.plan_route
  cruise.set_cruise
  main
end

main