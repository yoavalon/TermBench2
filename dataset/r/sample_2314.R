FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    target = NULL,
    climb_rate = NULL,
    descent_rate = NULL,
    
    initialize = function(initial_altitude, target_altitude, rate_of_climb, rate_of_descent) {
      self$altitude <- initial_altitude
      self$target <- target_altitude
      self$climb_rate <- rate_of_climb
      self$descent_rate <- rate_of_descent
    },
    
    update_altitude = function() {
      if (self$altitude < self$target) {
        self$altitude <- self$altitude + self$climb_rate
      } else if (self$altitude > self$target) {
        self$altitude <- self$altitude - self$descent_rate
      }
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    flight = NULL,
    cruise = NULL,
    hold = NULL,
    time_elapsed = 0,
    
    initialize = function(flight, cruise_altitude, hold_time) {
      self$flight <- flight
      self$cruise <- cruise_altitude
      self$hold <- hold_time
    },
    
    plan_cruise = function() {
      self$flight$altitude <- self$cruise
      while (self$time_elapsed < self$hold) {
        self$time_elapsed <- self$time_elapsed + 1
      }
    }
  )
)

main <- function() {
  initial <- 1000
  target <- 30000
  climb <- 100
  descent <- 50
  hold <- 600
  flight <- FlightTrajectory$new(initial, target, climb, descent)
  planner <- CruiseAltitudePlanner$new(flight, target, hold)
  while (TRUE) {
    flight$update_altitude()
    planner$plan_cruise()
  }
}

main()