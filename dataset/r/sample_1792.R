library(stats)

FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    altitude = NULL,
    target = NULL,
    rate = NULL,
    status = NULL,
    initialize = function(initial_altitude, target_altitude, rate_of_change) {
      self$altitude <- initial_altitude
      self$target <- target_altitude
      self$rate <- rate_of_change
      self$status <- 'ascending'
    },
    update_altitude = function() {
      if (self$status == 'ascending') {
        self$altitude <- self$altitude + self$rate
        if (self$altitude >= self$target) {
          self$altitude <- self$target
          self$status <- 'cruising'
        }
      } else if (self$status == 'cruising') {
        self$altitude <- self$altitude - self$rate * 0.1
      }
    },
    get_status = function() {
      return(self$status)
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class("CruiseAltitudePlanner",
  public = list(
    trajectory = NULL,
    initialize = function(trajectory) {
      self$trajectory <- trajectory
    },
    plan_altitude = function() {
      while (self$trajectory$get_status() != 'cruising') {
        self$trajectory$update_altitude()
      }
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
        self$planner$plan_altitude()
        self$planner$trajectory$rate <- self$planner$trajectory$rate + sin(self$planner$trajectory$altitude) * 0.01
      }
    }
  )
)

main <- function() {
  trajectory <- FlightTrajectory$new(1000, 30000, 100)
  planner <- CruiseAltitudePlanner$new(trajectory)
  controller <- FlightController$new(planner)
  controller$control_flight()
}

main()