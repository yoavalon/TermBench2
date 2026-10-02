FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    max_altitude = NULL,
    climb_rate = NULL,
    descent_rate = NULL,
    initialize = function(initial_altitude, max_altitude, rate_of_climb, rate_of_descent) {
      self$altitude <- initial_altitude
      self$max_altitude <- max_altitude
      self$climb_rate <- rate_of_climb
      self$descent_rate <- descent_rate
    },
    update_altitude = function(action) {
      if (action == 'climb') {
        self$altitude <- self$altitude + self$climb_rate
        if (self$altitude > self$max_altitude) {
          self$altitude <- self$max_altitude
        }
      } else if (action == 'descend') {
        self$altitude <- self$altitude - self$descent_rate
        if (self$altitude < 0) {
          self$altitude <- 0
        }
      }
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    target = NULL,
    tolerance = NULL,
    initialize = function(target_altitude, tolerance) {
      self$target <- target_altitude
      self$tolerance <- tolerance
    },
    is_within_tolerance = function(current_altitude) {
      return(abs(current_altitude - self$target) <= self$tolerance)
    }
  )
)

FlightControlSystem <- R6::R6Class("FlightControlSystem",
  public = list(
    trajectory = NULL,
    planner = NULL,
    initialize = function(trajectory, planner) {
      self$trajectory <- trajectory
      self$planner <- planner
    },
    control_loop = function() {
      while (TRUE) {
        if (!self$planner$is_within_tolerance(self$trajectory$altitude)) {
          if (self$trajectory$altitude < self$planner$target) {
            self$trajectory$update_altitude('climb')
          } else {
            self$trajectory$update_altitude('descend')
          }
        } else {
          self$trajectory$update_altitude('descend')
        }
      }
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  max_altitude <- 35000
  rate_of_climb <- 1000
  rate_of_descent <- 500
  target_altitude <- 30000
  tolerance <- 1000
  trajectory <- FlightTrajectory$new(initial_altitude, max_altitude, rate_of_climb, rate_of_descent)
  planner <- CruiseAltitudePlanner$new(target_altitude, tolerance)
  control_system <- FlightControlSystem$new(trajectory, planner)
  control_system$control_loop()
}

main()