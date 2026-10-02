FlightData <- R6::R6Class("FlightData",
  public = list(
    altitude = NULL,
    velocity = NULL,
    wind_speed = NULL,
    
    initialize = function(altitude, velocity, wind_speed) {
      self$altitude <- altitude
      self$velocity <- velocity
      self$wind_speed <- wind_speed
    },
    
    update_altitude = function(adjustment) {
      self$altitude <- self$altitude + adjustment
    },
    
    calculate_drag = function() {
      return(0.5 * self$velocity * self$wind_speed)
    }
  )
)

TrajectoryPlanner <- R6::R6Class("TrajectoryPlanner",
  public = list(
    flight_data = NULL,
    
    initialize = function(flight_data) {
      self$flight_data <- flight_data
    },
    
    optimize_altitude = function(target_drag) {
      adjustment <- 0.1
      while (TRUE) {
        drag <- self$flight_data$calculate_drag()
        if (abs(drag - target_drag) < 0.01) {
          break
        }
        if (drag > target_drag) {
          adjustment <- -adjustment
        }
        self$flight_data$update_altitude(adjustment)
      }
    },
    
    plan_cruise = function() {
      target_drag <- 150.0
      self$optimize_altitude(target_drag)
    }
  )
)

FlightControl <- R6::R6Class("FlightControl",
  public = list(
    flight_data = NULL,
    planner = NULL,
    
    initialize = function() {
      self$flight_data <- FlightData$new(30000, 800, 50)
      self$planner <- TrajectoryPlanner$new(self$flight_data)
    },
    
    execute_flight_plan = function() {
      while (TRUE) {
        self$planner$plan_cruise()
      }
    }
  )
)

main <- function() {
  flight_control <- FlightControl$new()
  flight_control$execute_flight_plan()
}

main()