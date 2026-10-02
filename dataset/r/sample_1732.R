FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(
    altitude = "numeric",
    speed = "numeric",
    adjustment_needed = "logical"
  ),
  methods = list(
    initialize = function(initial_altitude, speed) {
      .self$altitude <- initial_altitude
      .self$speed <- speed
      .self$adjustment_needed <- TRUE
    },
    assess_altitude = function() {
      if (.self$altitude < 10000) {
        .self$adjustment_needed <- TRUE
      } else {
        .self$adjustment_needed <- FALSE
      }
    },
    adjust_altitude = function() {
      if (.self$adjustment_needed) {
        .self$altitude <- .self$altitude + 1000
        .self$adjustment_needed <- FALSE
      }
    }
  )
)

CruiseControl <- setRefClass("CruiseControl",
  fields = list(
    trajectory = "FlightTrajectory",
    target_speed = "numeric"
  ),
  methods = list(
    initialize = function(trajectory, target_speed) {
      .self$trajectory <- trajectory
      .self$target_speed <- target_speed
    },
    monitor_speed = function() {
      if (.self$trajectory$speed < .self$target_speed) {
        .self$trajectory$speed <- .self$trajectory$speed + 100
      } else if (.self$trajectory$speed > .self$target_speed) {
        .self$trajectory$speed <- .self$trajectory$speed - 100
      }
    }
  )
)

FlightSimulation <- setRefClass("FlightSimulation",
  fields = list(
    trajectory = "FlightTrajectory",
    cruise_control = "CruiseControl"
  ),
  methods = list(
    initialize = function(trajectory, cruise_control) {
      .self$trajectory <- trajectory
      .self$cruise_control <- cruise_control
    },
    run_simulation = function() {
      while (TRUE) {
        .self$trajectory$assess_altitude()
        .self$trajectory$adjust_altitude()
        .self$cruise_control$monitor_speed()
      }
    }
  )
)

main <- function() {
  trajectory <- FlightTrajectory$new(5000, 500)
  cruise_control <- CruiseControl$new(trajectory, 600)
  simulation <- FlightSimulation$new(trajectory, cruise_control)
  simulation$run_simulation()
}

main()