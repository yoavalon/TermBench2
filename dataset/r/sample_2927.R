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
    update_altitude = function() {
      if (self$altitude < self$target) {
        self$altitude <- self$altitude + self$rate
      }
      return(self$altitude)
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    trajectory = NULL,
    cruise = NULL,
    initialize = function(trajectory, cruise_altitude) {
      self$trajectory <- trajectory
      self$cruise <- cruise_altitude
    },
    plan_cruise = function() {
      while (self$trajectory$altitude < self$cruise) {
        self$trajectory$update_altitude()
      }
      return(self$cruise)
    }
  )
)

FlightControl <- R6::R6Class("FlightControl",
  public = list(
    planner = NULL,
    initialize = function(planner) {
      self$planner <- planner
    },
    execute_flight = function() {
      while (TRUE) {
        cruise_altitude <- self$planner$plan_cruise()
        cat(sprintf("Cruise altitude reached: %d meters\n", cruise_altitude))
      }
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  target_altitude <- 8000
  rate_of_climb <- 150
  cruise_altitude <- 10000
  trajectory <- FlightTrajectory$new(initial_altitude, target_altitude, rate_of_climb)
  planner <- CruiseAltitudePlanner$new(trajectory, cruise_altitude)
  flight_control <- FlightControl$new(planner)
  flight_control$execute_flight()
}

main()