FlightParameters <- R6::R6Class(
  "FlightParameters",
  public = list(
    altitude = NULL,
    target = NULL,
    climb_rate = NULL,
    descent_rate = NULL,
    initialize = function(initial_altitude, target_altitude, max_climb_rate, descent_rate) {
      self$altitude <- initial_altitude
      self$target <- target_altitude
      self$climb_rate <- max_climb_rate
      self$descent_rate <- descent_rate
    }
  )
)

FlightControl <- R6::R6Class(
  "FlightControl",
  public = list(
    params = NULL,
    initialize = function(parameters) {
      self$params <- parameters
    },
    adjust_altitude = function() {
      if (self$params$altitude < self$params$target) {
        self$params$altitude <- self$params$altitude + self$params$climb_rate
      } else if (self$params$altitude > self$params$target) {
        self$params$altitude <- self$params$altitude - self$params$descent_rate
      }
      return(self$params$altitude)
    }
  )
)

FlightSimulation <- R6::R6Class(
  "FlightSimulation",
  public = list(
    control = NULL,
    is_operational = TRUE,
    initialize = function(control) {
      self$control <- control
    },
    run_simulation = function() {
      while (self$is_operational) {
        new_altitude <- self$control$adjust_altitude()
        if (new_altitude == self$control$params$target) {
          self$is_operational <- FALSE
        }
        cat('Current Altitude:', new_altitude, '\n')
      }
    }
  )
)

main <- function() {
  params <- FlightParameters$new(5000, 35000, 1500, 500)
  control <- FlightControl$new(params)
  simulation <- FlightSimulation$new(control)
  simulation$run_simulation()
}

main()