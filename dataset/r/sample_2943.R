FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    rate = NULL,
    initialize = function(initial_altitude, rate_of_climb) {
      self$altitude <- initial_altitude
      self$rate <- rate_of_climb
    },
    update_altitude = function() {
      self$altitude <- self$altitude + self$rate
    },
    get_altitude = function() {
      return(self$altitude)
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    target = NULL,
    step = NULL,
    initialize = function(target_altitude, step_increase) {
      self$target <- target_altitude
      self$step <- step_increase
    },
    is_cruise_altitude_reached = function(current_altitude) {
      return(current_altitude >= self$target)
    },
    adjust_altitude = function(current_altitude) {
      if (current_altitude < self$target) {
        return(current_altitude + self$step)
      } else {
        return(current_altitude)
      }
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
    execute = function() {
      while (TRUE) {
        current_altitude <- self$trajectory$get_altitude()
        if (self$planner$is_cruise_altitude_reached(current_altitude)) {
          self$trajectory$altitude <- self$planner$adjust_altitude(current_altitude)
        }
        self$trajectory$update_altitude()
      }
    }
  )
)

main <- function() {
  initial_altitude <- 5000
  rate_of_climb <- 100
  target_altitude <- 35000
  step_increase <- 500
  trajectory <- FlightTrajectory$new(initial_altitude, rate_of_climb)
  planner <- CruiseAltitudePlanner$new(target_altitude, step_increase)
  control_system <- FlightControlSystem$new(trajectory, planner)
  control_system$execute()
}

main()