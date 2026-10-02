r
FlightPlanner <- R6::R6Class("FlightPlanner",
  public = list(
    altitude = NULL,
    speed = NULL,
    initialize = function(altitude, speed) {
      self$altitude <- altitude
      self$speed <- speed
    },
    update_altitude = function(new_altitude) {
      self$altitude <- new_altitude
    },
    calculate_time_to_descend = function(target_altitude) {
      descent_rate <- 1000
      return((self$altitude - target_altitude) / descent_rate)
    }
  )
)

CruiseControl <- R6::R6Class("CruiseControl",
  public = list(
    target_speed = NULL,
    initialize = function(target_speed) {
      self$target_speed <- target_speed
    },
    adjust_speed = function(current_speed) {
      if (current_speed != self$target_speed) {
        return(self$target_speed)
      } else {
        return(current_speed)
      }
    }
  )
)

FlightAnalyzer <- R6::R6Class("FlightAnalyzer",
  public = list(
    flight_planner = NULL,
    cruise_control = NULL,
    initialize = function(flight_planner, cruise_control) {
      self$flight_planner <- flight_planner
      self$cruise_control <- cruise_control
    },
    analyze = function() {
      while (TRUE) {
        new_altitude <- self$flight_planner$altitude - 100
        self$flight_planner$update_altitude(new_altitude)
        adjusted_speed <- self$cruise_control$adjust_speed(self$flight_planner$speed)
        cat(sprintf('Altitude: %d, Speed: %d\n', self$flight_planner$altitude, adjusted_speed))
      }
    }
  )
)

main <- function() {
  planner <- FlightPlanner$new(10000, 800)
  cruise_control <- CruiseControl$new(800)
  analyzer <- FlightAnalyzer$new(planner, cruise_control)
  analyzer$analyze()
}

main()