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

CruisePlanner <- R6::R6Class("CruisePlanner",
  public = list(
    trajectory = NULL,
    cruise_altitude = NULL,
    cruise_speed = NULL,
    initialize = function(trajectory, cruise_altitude, cruise_speed) {
      self$trajectory <- trajectory
      self$cruise_altitude <- cruise_altitude
      self$cruise_speed <- cruise_speed
    },
    plan_cruise = function() {
      while (self$trajectory$update_altitude() < self$cruise_altitude) {
        # Do nothing
      }
      return(self$cruise_speed)
    }
  )
)

FlightController <- R6::R6Class("FlightController",
  public = list(
    planner = NULL,
    initialize = function(planner) {
      self$planner <- planner
    },
    control_flight = function() {
      while (TRUE) {
        cruise_speed <- self$planner$plan_cruise()
        cat(sprintf('Cruise Speed Set to: %d\n', cruise_speed))
      }
    }
  )
)

main <- function() {
  trajectory <- FlightTrajectory$new(initial_altitude = 500, target_altitude = 35000, rate_of_climb = 500)
  planner <- CruisePlanner$new(trajectory, cruise_altitude = 35000, cruise_speed = 850)
  controller <- FlightController$new(planner)
  controller$control_flight()
}

main()