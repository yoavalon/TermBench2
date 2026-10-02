FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    max_altitude = NULL,
    speed = NULL,
    climbing = NULL,
    initialize = function(initial_altitude, max_altitude, speed) {
      self$altitude <- initial_altitude
      self$max_altitude <- max_altitude
      self$speed <- speed
      self$climbing <- TRUE
    },
    adjust_altitude = function() {
      if (self$climbing) {
        self$altitude <- self$altitude + self$speed
        if (self$altitude >= self$max_altitude) {
          self$climbing <- FALSE
        }
      } else {
        self$altitude <- self$altitude - self$speed
        if (self$altitude <= 0) {
          self$climbing <- TRUE
        }
      }
    },
    simulate_flight = function() {
      while (TRUE) {
        self$adjust_altitude()
      }
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
        if (self$trajectory$climbing) {
          cat(sprintf('Climbing to %d meters\n', self$trajectory$altitude))
        } else {
          cat(sprintf('Descending to %d meters\n', self$trajectory$altitude))
        }
      }
    }
  )
)

main <- function() {
  trajectory <- FlightTrajectory$new(initial_altitude = 1000, max_altitude = 10000, speed = 100)
  planner <- CruiseAltitudePlanner$new(trajectory)
  planner$plan_cruise()
}

main()