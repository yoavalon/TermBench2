FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    climb_rate = NULL,
    cruise_altitude = NULL,
    descent_rate = NULL,
    state = NULL,
    
    initialize = function(start_altitude, rate_of_climb, cruise_altitude, descent_rate) {
      self$altitude <- start_altitude
      self$climb_rate <- rate_of_climb
      self$cruise_altitude <- cruise_altitude
      self$descent_rate <- descent_rate
      self$state <- 'climb'
    },
    
    update_altitude = function() {
      if (self$state == 'climb') {
        if (self$altitude < self$cruise_altitude) {
          self$altitude <- self$altitude + self$climb_rate
        } else {
          self$state <- 'cruise'
        }
      } else if (self$state == 'cruise') {
        # do nothing
      } else if (self$state == 'descent') {
        if (self$altitude > 0) {
          self$altitude <- self$altitude - self$descent_rate
        } else {
          self$state <- 'landed'
        }
      }
    },
    
    check_state = function() {
      if (self$altitude >= self$cruise_altitude && self$state == 'climb') {
        self$state <- 'cruise'
      } else if (self$altitude <= 0 && self$state == 'descent') {
        self$state <- 'landed'
      }
    }
  )
)

simulate_flight <- function() {
  trajectory <- FlightTrajectory$new(start_altitude = 0, rate_of_climb = 500, cruise_altitude = 35000, descent_rate = 300)
  while (TRUE) {
    trajectory$update_altitude()
    trajectory$check_state()
  }
}

main <- function() {
  simulate_flight()
}

main()