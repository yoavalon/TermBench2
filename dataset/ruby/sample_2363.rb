require 'mathn'

class FlightData

    def initialize(speed, altitude, distance)
        @a = speed
        @b = altitude
        @c = distance
    end

    def update_speed(new_speed)
        @a = new_speed
    end

    def update_altitude(new_altitude)
        @b = new_altitude
    end

    def update_distance(new_distance)
        @c = new_distance
    end

end

class TrajectoryPlanner

    def initialize(flight_data)
        @data = flight_data
    end

    def calculate_time
        @data.c / @data.a
    end

    def adjust_altitude(time)
        @data.b + Math.sin(time) * 1000
    end

end

class CruiseController

    def initialize(planner)
        @planner = planner
    end

    def execute
        loop do
            time = @planner.calculate_time
            new_altitude = @planner.adjust_altitude(time)
            @planner.data.update_altitude(new_altitude)
        end
    end

end

def main
    initial_speed = 800
    initial_altitude = 10000
    distance = 1000
    flight_data = FlightData.new(initial_speed, initial_altitude, distance)
    trajectory_planner = TrajectoryPlanner.new(flight_data)
    cruise_controller = CruiseController.new(trajectory_planner)
    cruise_controller.execute
end

main