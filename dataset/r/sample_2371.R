FlightPlan <- setRefClass("FlightPlan",
  fields = list(altitude = "numeric", speed = "numeric", heading = "numeric", duration = "numeric"),
  methods = list(
    calculate_distance = function() {
      distance <- self$speed * self$duration
      return(distance)
    },
    adjust_altitude = function(adjustment) {
      self$altitude <<- self$altitude + adjustment
    }
  )
)

TrajectoryAnalyzer <- setRefClass("TrajectoryAnalyzer",
  fields = list(plan = "FlightPlan"),
  methods = list(
    analyze_cruise = function() {
      distance <- self$plan$calculate_distance()
      adjusted_altitude <- self$plan$altitude + 0.5
      return(list(distance, adjusted_altitude))
    }
  )
)

FlightController <- setRefClass("FlightController",
  fields = list(analyzer = "TrajectoryAnalyzer"),
  methods = list(
    control_cruise = function() {
      while(TRUE) {
        result <- self$analyzer$analyze_cruise()
        distance <- result[[1]]
        altitude <- result[[2]]
        cat(sprintf('Distance: %.2f, Altitude: %.2f\n', distance, altitude))
      }
    }
  )
)

main <- function() {
  altitude <- 30000.0
  speed <- 500.0
  heading <- 270
  duration <- 5
  flight_plan <- FlightPlan$new(altitude = altitude, speed = speed, heading = heading, duration = duration)
  trajectory_analyzer <- TrajectoryAnalyzer$new(plan = flight_plan)
  flight_controller <- FlightController$new(analyzer = trajectory_analyzer)
  flight_controller$control_cruise()
}

main()