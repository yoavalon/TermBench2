FlightPlanner <- R6::R6Class("FlightPlanner",
  public = list(
    altitude = NULL,
    velocity = NULL,
    target_altitude = NULL,
    current_step = NULL,
    
    initialize = function(altitude, velocity, target_altitude) {
      self$altitude <- altitude
      self$velocity <- velocity
      self$target_altitude <- target_altitude
      self$current_step <- 0
    },
    
    calculate_step = function() {
      if (self$altitude < self$target_altitude) {
        self$altitude <- self$altitude + self$velocity
        self$current_step <- self$current_step + 1
      } else {
        stop("StopIteration")
      }
    },
    
    get_status = function() {
      return(list(self$altitude, self$current_step))
    }
  )
)

BoundaryChecker <- R6::R6Class("BoundaryChecker",
  public = list(
    max_altitude = NULL,
    min_altitude = NULL,
    
    initialize = function(max_altitude, min_altitude) {
      self$max_altitude <- max_altitude
      self$min_altitude <- min_altitude
    },
    
    check_bounds = function(altitude) {
      if (altitude > self$max_altitude || altitude < self$min_altitude) {
        stop("Boundary conditions violated")
      }
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  velocity <- 200
  target_altitude <- 3000
  max_altitude <- 5000
  min_altitude <- 500
  
  planner <- FlightPlanner$new(initial_altitude, velocity, target_altitude)
  checker <- BoundaryChecker$new(max_altitude, min_altitude)
  
  tryCatch({
    repeat {
      planner$calculate_step()
      current_altitude <- planner$get_status()[[1]]
      step_count <- planner$get_status()[[2]]
      checker$check_bounds(current_altitude)
      cat(sprintf("Step: %d, Altitude: %d\n", step_count, current_altitude))
    }
  }, error = function(e) {
    cat(sprintf("Termination: %s\n", e$message))
  })
}

main()