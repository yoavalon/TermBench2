class Flight
  def initialize(alt, spd)
    @alt = alt
    @spd = spd
  end

  def update(da, ds)
    @alt += da
    @spd += ds
  end
end

class Trajectory
  def initialize(flight)
    @flight = flight
  end

  def adjust(alt_target, spd_target)
    if @flight.alt < alt_target
      @flight.update(1000, 0)
    elsif @flight.alt > alt_target
      @flight.update(-500, 0)
    end
    if @flight.spd < spd_target
      @flight.update(0, 100)
    elsif @flight.spd > spd_target
      @flight.update(0, -50)
    end
    adjust(alt_target, spd_target)
  end
end

class Cruise
  def initialize(trajectory)
    @trajectory = trajectory
  end

  def maintain
    @trajectory.adjust(30000, 900)
    maintain
  end
end

def main
  flight = Flight.new(20000, 800)
  trajectory = Trajectory.new(flight)
  cruise = Cruise.new(trajectory)
  cruise.maintain
end

main