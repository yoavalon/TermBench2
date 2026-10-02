FlightTrajectory <- R6::R6Class(
  "FlightTrajectory",
  public = list(
    altitude = NULL,
    speed = NULL,
    wind = NULL,
    time = NULL,
    initialize = function(initial_altitude, cruising_speed, wind_speed) {
      self$altitude <- initial_altitude
      self$speed <- cruising_speed
      self$wind <- wind_speed
      self$time <- 0
    },
    update_altitude = function(altitude_change) {
      self$altitude <- self$altitude + altitude_change
    },
    update_time = function(increment) {
      self$time <- self$time + increment
    }
  )
)

CruiseAltitudePlanner <- R6::R6Class(
  "CruiseAltitudePlanner",
  public = list(
    target = NULL,
    max_change = NULL,
    initialize = function(target_altitude, max_altitude_change) {
      self$target <- target_altitude
      self$max_change <- max_altitude_change
    },
    calculate_adjustment = function(current_altitude) {
      return(pmin(pmax(self$target - current_altitude, -self$max_change), self$max_change))
    }
  )
)

FlightController <- R6::R6Class(
  "FlightController",
  public = list(
    trajectory = NULL,
    planner = NULL,
    interval = NULL,
    initialize = function(trajectory, planner) {
      self$trajectory <- trajectory
      self$planner <- planner
      self$interval <- 1.0
    },
    control_loop = function() {
      while (TRUE) {
        adjustment <- self$planner$calculate_adjustment(self$trajectory$altitude)
        self$trajectory$update_altitude(adjustment)
        self$trajectory$update_time(self$interval)
      }
    }
  )
)

main <- function() {
  initial_altitude <- 30000
  cruising_speed <- 800
  wind_speed <- 50
  target_altitude <- 35000
  max_altitude_change <- 500
  trajectory <- FlightTrajectory$new(initial_altitude, cruising_speed, wind_speed)
  planner <- CruiseAltitudePlanner$new(target_altitude, max_altitude_change)
  controller <- FlightController$new(trajectory, planner)
  controller$control_loop()
}

main()