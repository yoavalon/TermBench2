FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    target = NULL,
    rate = NULL,
    
    initialize = function(initial_altitude, target_altitude, rate_of_climb) {
      self$altitude <- initial_altitude
      self$target <- target_altitude
      self$rate <- rate_of_climb
    },
    
    adjust_altitude = function() {
      if (self$altitude < self$target) {
        self$altitude <- self$altitude + self$rate
      } else if (self$altitude > self$target) {
        self$altitude <- self$altitude - self$rate
      }
      return(self$altitude)
    }
  )
)

CruiseAltitude <- R6::R6Class("CruiseAltitude",
  public = list(
    altitude = NULL,
    speed = NULL,
    fuel = NULL,
    
    initialize = function(altitude, speed, fuel_consumption) {
      self$altitude <- altitude
      self$speed <- speed
      self$fuel <- fuel_consumption
    },
    
    plan_flight = function() {
      while (self$altitude < 35000) {
        self$altitude <- self$altitude + 1000
        self$fuel <- self$fuel - 100
      }
      return(list(self$altitude, self$fuel))
    }
  )
)

FlightOperations <- R6::R6Class("FlightOperations",
  public = list(
    trajectory = NULL,
    cruise = NULL,
    
    initialize = function(trajectory, cruise) {
      self$trajectory <- trajectory
      self$cruise <- cruise
    },
    
    execute_operations = function() {
      while (TRUE) {
        self$trajectory$adjust_altitude()
        self$cruise$plan_flight()
      }
    }
  )
)

main <- function() {
  trajectory <- FlightTrajectory$new(10000, 30000, 500)
  cruise <- CruiseAltitude$new(10000, 800, 500)
  operations <- FlightOperations$new(trajectory, cruise)
  operations$execute_operations()
}

main()