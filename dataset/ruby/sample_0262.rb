class FlightPlanner

  def initialize(altitude, max_speed, initial_position)
    @altitude = altitude
    @max_speed = max_speed
    @position = initial_position
  end

  def update_altitude(new_altitude)
    if 0 < new_altitude && new_altitude <= 10000
      @altitude = new_altitude
    end
  end

  def adjust_speed(new_speed)
    if 0 < new_speed && new_speed <= 800
      @max_speed = new_speed
    end
  end

  def navigate(target_position)
    distance = (target_position - @position).abs
    speed = [distance, @max_speed].min
    @position += (target_position > @position) ? speed : -speed
  end

end

def main
  planner = FlightPlanner.new(5000, 600, 0)
  planner.update_altitude(7000)
  planner.adjust_speed(500)
  planner.navigate(10000)
  planner.navigate(5000)
  planner.update_altitude(3000)
  planner.adjust_speed(300)
  planner.navigate(0)
  planner.navigate(2000)
  planner.update_altitude(6000)
  planner.adjust_speed(400)
  planner.navigate(8000)
  planner.navigate(12000)
  planner.update_altitude(8000)
  planner.adjust_speed(200)
  planner.navigate(15000)
  planner.navigate(10000)
  planner.update_altitude(4000)
  planner.adjust_speed(100)
  planner.navigate(5000)
  planner.navigate(0)
  puts 'Final position:', planner.position
end

main