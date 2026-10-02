FlightPlanner <- R6::R6Class("FlightPlanner",
  public = list(
    initial_altitude = NULL,
    target_altitude = NULL,
    speed = NULL,
    descent_rate = NULL,
    altitude = NULL,
    target = NULL,
    time = NULL,
    
    initialize = function(initial_altitude, target_altitude, speed, descent_rate) {
      self$altitude <- initial_altitude
      self$target <- target_altitude
      self$speed <- speed
      self$descent <- descent_rate
      self$time <- 0
    },
    
    update_altitude = function() {
      if (self$altitude > self$target) {
        self$altitude <- self$altitude - (self$descent * self$speed)
        self$time <- self$time + 1
      } else {
        self$altitude <- self$target
      }
    },
    
    get_flight_data = function() {
      return(list(self$altitude, self$time))
    }
  )
)

TrajectoryAnalyzer <- R6::R6Class("TrajectoryAnalyzer",
  public = list(
    planner = NULL,
    
    initialize = function(planner) {
      self$planner <- planner
    },
    
    analyze = function() {
      data <- list()
      while (self$planner$altitude > self$planner$target) {
        self$planner$update_altitude()
        data <- c(data, list(self$planner$get_flight_data()))
      }
      return(data)
    }
  )
)

main <- function() {
  initial_altitude <- 35000.0
  target_altitude <- 10000.0
  speed <- 0.5
  descent_rate <- 100.0
  planner <- FlightPlanner$new(initial_altitude, target_altitude, speed, descent_rate)
  analyzer <- TrajectoryAnalyzer$new(planner)
  trajectory_data <- analyzer$analyze()
  for (i in seq_along(trajectory_data)) {
    cat(sprintf('Time: %d, Altitude: %.2f\n', trajectory_data[[i]][[2]], trajectory_data[[i]][[1]]))
  }
}

main()