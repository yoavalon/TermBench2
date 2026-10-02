FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(
    altitude = "numeric",
    target = "numeric",
    step = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, target_altitude, step) {
      .self$altitude <- initial_altitude
      .self$target <- target_altitude
      .self$step <- step
    },
    adjust_altitude = function() {
      if (.self$altitude < .self$target) {
        .self$altitude <- .self$altitude + .self$step
      } else {
        .self$altitude <- .self$altitude - .self$step
      }
      return(.self$altitude)
    }
  )
)

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
  fields = list(
    trajectory = "FlightTrajectory"
  ),
  methods = list(
    initialize = function(trajectory) {
      .self$trajectory <- trajectory
    },
    plan_altitude = function() {
      while (TRUE) {
        new_altitude <- .self$trajectory$adjust_altitude()
        if (abs(new_altitude - .self$trajectory$target) < .self$trajectory$step) {
          break
        }
      }
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(
    planner = "CruiseAltitudePlanner"
  ),
  methods = list(
    initialize = function(planner) {
      .self$planner <- planner
    },
    run = function() {
      while (TRUE) {
        .self$planner$plan_altitude()
      }
    }
  )
)

main <- function() {
  initial <- 10000
  target <- 30000
  step <- 1000
  trajectory <- FlightTrajectory$new(initial, target, step)
  planner <- CruiseAltitudePlanner$new(trajectory)
  simulation <- Simulation$new(planner)
  simulation$run()
}

main()