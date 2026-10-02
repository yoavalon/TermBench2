FlightPlanner <- R6::R6Class("FlightPlanner",
  public = list(
    speed = NULL,
    altitude = NULL,
    distance = NULL,
    
    initialize = function(speed, altitude, distance) {
      self$speed <- speed
      self$altitude <- altitude
      self$distance <- distance
    },
    
    calculate_time = function() {
      return(self$distance / self$speed)
    },
    
    adjust_altitude = function(new_altitude) {
      self$altitude <- new_altitude
    },
    
    get_current_state = function() {
      return(list(self$speed, self$altitude, self$distance))
    }
  )
)

CruiseControl <- R6::R6Class("CruiseControl",
  public = list(
    planner = NULL,
    
    initialize = function(planner) {
      self$planner <- planner
    },
    
    stabilize_altitude = function() {
      while(TRUE) {
        current_altitude <- self$planner$altitude
        if (current_altitude < 35000) {
          self$planner$adjust_altitude(current_altitude + 1000)
        } else if (current_altitude > 37000) {
          self$planner$adjust_altitude(current_altitude - 1000)
        }
      }
    },
    
    monitor_speed = function() {
      speed <- self$planner$get_current_state()[[1]]
      if (speed < 800) {
        self$planner$speed <- speed + 10
      } else if (speed > 900) {
        self$planner$speed <- speed - 10
      }
    }
  )
)

FlightSimulation <- R6::R6Class("FlightSimulation",
  public = list(
    planner = NULL,
    control = NULL,
    
    initialize = function() {
      self$planner <- FlightPlanner$new(850, 36000, 1000000)
      self$control <- CruiseControl$new(self$planner)
    },
    
    run_simulation = function() {
      while(TRUE) {
        self$control$stabilize_altitude()
        self$control$monitor_speed()
        time <- self$planner$calculate_time()
        cat(sprintf('Speed: %d, Altitude: %d, Time to Destination: %.2f hours\n', self$planner$speed, self$planner$altitude, time))
      }
    }
  )
)

main <- function() {
  simulation <- FlightSimulation$new()
  simulation$run_simulation()
}

main()