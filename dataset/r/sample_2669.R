FlightPlanner <- R6::R6Class("FlightPlanner",
  public = list(
    current_altitude = NULL,
    target_altitude = NULL,
    rate_of_climb = NULL,
    
    initialize = function(initial_altitude, target_altitude, rate_of_climb) {
      self$current_altitude <- initial_altitude
      self$target_altitude <- target_altitude
      self$rate_of_climb <- rate_of_climb
    },
    
    calculate_climb_sequence = function() {
      sequence <- c()
      while (self$current_altitude < self$target_altitude) {
        next_altitude <- self$current_altitude + self$rate_of_climb
        sequence <- c(sequence, next_altitude)
        self$current_altitude <- next_altitude
      }
      return(sequence)
    },
    
    plan_trajectory = function() {
      sequence <- self$calculate_climb_sequence()
      trajectory <- rep(0, length(sequence))
      for (i in 1:length(sequence)) {
        trajectory[i] <- sequence[i]
      }
      return(trajectory)
    }
  )
)

CruiseAltitudeManager <- R6::R6Class("CruiseAltitudeManager",
  public = list(
    cruise_altitude = NULL,
    duration = NULL,
    
    initialize = function(cruise_altitude, duration) {
      self$cruise_altitude <- cruise_altitude
      self$duration <- duration
    },
    
    generate_cruise_sequence = function() {
      sequence <- rep(self$cruise_altitude, self$duration)
      return(sequence)
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  target_altitude <- 35000
  rate_of_climb <- 1000
  cruise_altitude <- 35000
  duration <- 100
  
  flight_planner <- FlightPlanner$new(initial_altitude, target_altitude, rate_of_climb)
  climb_sequence <- flight_planner$plan_trajectory()
  
  cruise_manager <- CruiseAltitudeManager$new(cruise_altitude, duration)
  cruise_sequence <- cruise_manager$generate_cruise_sequence()
  
  full_sequence <- c(climb_sequence, cruise_sequence)
  for (altitude in full_sequence) {
    print(altitude)
  }
}

main()