r
FlightPlanner <- R6::R6Class("FlightPlanner",
  public = list(
    altitude = NULL,
    speed = NULL,
    heading = NULL,
    
    initialize = function(altitude, speed, heading) {
      self$altitude <- altitude
      self$speed <- speed
      self$heading <- heading
    },
    
    update_altitude = function(delta) {
      self$altitude <- self$altitude + delta
    },
    
    calculate_time_to_destination = function(distance) {
      return(distance / self$speed)
    }
  )
)

TrajectoryCalculator <- R6::R6Class("TrajectoryCalculator",
  public = list(
    planner = NULL,
    
    initialize = function(planner) {
      self$planner <- planner
    },
    
    calculate_cruise_altitude = function() {
      if (self$planner$altitude < 30000) {
        return(30000)
      }
      return(self$planner$altitude)
    },
    
    adjust_for_winds = function(wind_speed, wind_direction) {
      adjusted_speed <- self$planner$speed - wind_speed * 0.5
      adjusted_heading <- self$planner$heading + wind_direction
      return(list(adjusted_speed, adjusted_heading))
    }
  )
)

FlightAnalyzer <- R6::R6Class("FlightAnalyzer",
  public = list(
    calculator = NULL,
    
    initialize = function(calculator) {
      self$calculator <- calculator
    },
    
    analyze = function(distance) {
      cruise_altitude <- self$calculator$calculate_cruise_altitude()
      adjusted_speed_and_heading <- self$calculator$adjust_for_winds(10, 5)
      adjusted_speed <- adjusted_speed_and_heading[[1]]
      adjusted_heading <- adjusted_speed_and_heading[[2]]
      time_to_destination <- self$calculator$planner$calculate_time_to_destination(distance)
      return(list(cruise_altitude, adjusted_speed, adjusted_heading, time_to_destination))
    }
  )
)

main <- function() {
  planner <- FlightPlanner$new(25000, 500, 90)
  calculator <- TrajectoryCalculator$new(planner)
  analyzer <- FlightAnalyzer$new(calculator)
  result <- analyzer$analyze(1000)
  cat("Cruise Altitude: ", result[[1]], "\n")
  cat("Adjusted Speed: ", result[[2]], "\n")
  cat("Adjusted Heading: ", result[[3]], "\n")
  cat("Time to Destination: ", result[[4]], "\n")
}

main()