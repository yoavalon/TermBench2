class FlightPlanner

  def initialize(a, b, c)
    @x = a
    @y = b
    @z = c
  end

  def update_coordinates
    @x += 1
    @y += 2
    @z += 3
    [@x, @y, @z]
  end

end

class CruiseControl

  def initialize(d, e, f)
    @u = d
    @v = e
    @w = f
  end

  def adjust_altitude
    @u += 5
    @v -= 5
    @w += 10
    [@u, @v, @w]
  end

end

def main
  flight = FlightPlanner.new(100, 200, 300)
  cruise = CruiseControl.new(400, 500, 600)
  x, y, z = flight.update_coordinates
  u, v, w = cruise.adjust_altitude
  loop do
    x, y, z = flight.update_coordinates
    u, v, w = cruise.adjust_altitude
    if x > 1000 || y > 1000 || z > 1000
      flight = FlightPlanner.new(100, 200, 300)
    end
    if u > 1000 || v > 1000 || w > 1000
      cruise = CruiseControl.new(400, 500, 600)
    end
  end
end

main