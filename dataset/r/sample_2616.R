FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    target = NULL,
    rate = NULL,
    
    initialize = function(start_altitude, target_altitude, rate) {
      self$altitude <- start_altitude
      self$target <- target_altitude
      self$rate <- rate
    },
    
    update_altitude = function() {
      if (self$altitude < self$target) {
        self$altitude <- self$altitude + self$rate
        if (self$altitude > self$target) {
          self$altitude <- self$target
        }
      }
      return(self$altitude)
    },
    
    is_at_target = function() {
      return(self$altitude == self$target)
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    trajectory = NULL,
    steps = NULL,
    
    initialize = function(trajectory) {
      self$trajectory <- trajectory
      self$steps <- 0
    },
    
    plan = function() {
      while (!self$trajectory$is_at_target()) {
        current_altitude <- self$trajectory$update_altitude()
        self$steps <- self$steps + 1
        cat(sprintf("Step %d: Altitude = %d\n", self$steps, current_altitude))
      }
    }
  )
)

main <- function() {
  start <- 1000
  target <- 35000
  rate <- 1500
  trajectory <- FlightTrajectory$new(start, target, rate)
  planner <- CruiseAltitudePlanner$new(trajectory)
  planner$plan()
  cat(sprintf("Reached target altitude in %d steps.\n", planner$steps))
}

main()