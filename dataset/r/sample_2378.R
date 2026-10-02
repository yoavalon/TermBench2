FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(
    altitude = "numeric",
    rate = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, rate_of_change) {
      .self$altitude <- initial_altitude
      .self$rate <- rate_of_change
    },
    update_altitude = function() {
      .self$altitude <<- .self$altitude + .self$rate
    },
    get_altitude = function() {
      return(.self$altitude)
    }
  )
)

CruisePlanner <- setRefClass("CruisePlanner",
  fields = list(
    target = "numeric"
  ),
  methods = list(
    initialize = function(target_altitude) {
      .self$target <- target_altitude
    },
    evaluate_altitude = function(current_altitude) {
      return(abs(.self$target - current_altitude))
    },
    adjust_rate = function(rate, error) {
      if (error > 1000) {
        return(rate * 1.1)
      } else if (error < 500) {
        return(rate * 0.9)
      } else {
        return(rate)
      }
    }
  )
)

Simulation <- setRefClass("Simulation",
  fields = list(
    trajectory = "FlightTrajectory",
    planner = "CruisePlanner"
  ),
  methods = list(
    initialize = function(trajectory, planner) {
      .self$trajectory <- trajectory
      .self$planner <- planner
    },
    run = function() {
      while (TRUE) {
        current_altitude <- .self$trajectory$get_altitude()
        error <- .self$planner$evaluate_altitude(current_altitude)
        if (error < 10) {
          .self$trajectory$rate <<- 0
        } else {
          .self$trajectory$rate <<- .self$planner$adjust_rate(.self$trajectory$rate, error)
        }
        .self$trajectory$update_altitude()
      }
    }
  )
)

main <- function() {
  initial_altitude <- 1000.0
  rate_of_change <- 100.0
  target_altitude <- 30000.0
  trajectory <- FlightTrajectory$new(initial_altitude, rate_of_change)
  planner <- CruisePlanner$new(target_altitude)
  simulation <- Simulation$new(trajectory, planner)
  simulation$run()
}

main()