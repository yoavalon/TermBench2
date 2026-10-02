FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    a = NULL,
    t = NULL,
    r = NULL,
    d = NULL,
    current_altitude = NULL,
    is_ascent = NULL,
    initialize = function(initial_altitude, target_altitude, rate_of_climb, descent_rate) {
      self$a <- initial_altitude
      self$t <- target_altitude
      self$r <- rate_of_climb
      self$d <- descent_rate
      self$current_altitude <- initial_altitude
      self$is_ascent <- TRUE
    },
    adjust_altitude = function() {
      if (self$is_ascent) {
        if (self$current_altitude < self$t) {
          self$current_altitude <- self$current_altitude + self$r
        } else {
          self$is_ascent <- FALSE
        }
      } else if (self$current_altitude > self$t) {
        self$current_altitude <- self$current_altitude - self$d
      }
    },
    get_current_altitude = function() {
      return(self$current_altitude)
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    trajectory = NULL,
    initialize = function(trajectory) {
      self$trajectory <- trajectory
    },
    plan_cruise = function() {
      while (TRUE) {
        self$trajectory$adjust_altitude()
        current_altitude <- self$trajectory$get_current_altitude()
        if (current_altitude == self$trajectory$t) {
          self$trajectory$is_ascent <- TRUE
        }
      }
    }
  )
)

FlightControlSystem <- R6::R6Class("FlightControlSystem",
  public = list(
    planner = NULL,
    initialize = function(planner) {
      self$planner <- planner
    },
    execute = function() {
      while (TRUE) {
        self$planner$plan_cruise()
      }
    }
  )
)

main <- function() {
  initial_altitude <- 5000.0
  target_altitude <- 35000.0
  rate_of_climb <- 100.0
  descent_rate <- 50.0
  trajectory <- FlightTrajectory$new(initial_altitude, target_altitude, rate_of_climb, descent_rate)
  planner <- CruiseAltitudePlanner$new(trajectory)
  control_system <- FlightControlSystem$new(planner)
  control_system$execute()
}

main()