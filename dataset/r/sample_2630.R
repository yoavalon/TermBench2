SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    start = NULL,
    step = NULL,
    count = NULL,
    current = NULL,
    index = NULL,
    initialize = function(start, step, count) {
      self$start <- start
      self$step <- step
      self$count <- count
      self$current <- start
      self$index <- 0
    },
    next = function() {
      if (self$index < self$count) {
        value <- self$current
        self$current <- self$current + self$step
        self$index <- self$index + 1
        return(value)
      } else {
        return(NULL)
      }
    }
  )
)

FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    initial_altitude = NULL,
    rate_of_climb = NULL,
    cruise_altitude = NULL,
    descent_rate = NULL,
    sequence = NULL,
    current_altitude = NULL,
    initialize = function(initial_altitude, rate_of_climb, cruise_altitude, descent_rate, sequence) {
      self$initial_altitude <- initial_altitude
      self$rate_of_climb <- rate_of_climb
      self$cruise_altitude <- cruise_altitude
      self$descent_rate <- descent_rate
      self$sequence <- sequence
      self$current_altitude <- initial_altitude
    },
    plan_cruise = function() {
      climb_sequence <- SequenceGenerator$new(self$initial_altitude, self$rate_of_climb, 100)
      while (TRUE) {
        next_altitude <- climb_sequence$next()
        if (is.null(next_altitude) || next_altitude >= self$cruise_altitude) {
          break
        }
        self$current_altitude <- next_altitude
      }
      if (self$current_altitude < self$cruise_altitude) {
        self$current_altitude <- self$cruise_altitude
      }
      descent_sequence <- SequenceGenerator$new(self$current_altitude, -self$descent_rate, 100)
      while (TRUE) {
        next_altitude <- descent_sequence$next()
        if (is.null(next_altitude) || next_altitude <= 0) {
          break
        }
        self$current_altitude <- next_altitude
      }
      if (self$current_altitude > 0) {
        self$current_altitude <- 0
      }
    }
  )
)

main <- function() {
  sequence <- SequenceGenerator$new(0, 100, 200)
  trajectory <- FlightTrajectory$new(1000, 500, 30000, 200, sequence)
  trajectory$plan_cruise()
  cat('Final Altitude:', trajectory$current_altitude, '\n')
}

main()