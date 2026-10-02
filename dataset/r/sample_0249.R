FlightTrajectory <- setRefClass(
  "FlightTrajectory",
  fields = list(
    altitude = "numeric",
    max_altitude = "numeric",
    speed = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, max_altitude, speed) {
      .self$altitude <<- initial_altitude
      .self$max_altitude <<- max_altitude
      .self$speed <<- speed
    },
    update_altitude = function(time) {
      .self$altitude <<- .self$altitude + .self$speed * time
      if (.self$altitude > .self$max_altitude) {
        .self$altitude <<- .self$max_altitude
      }
    }
  )
)

CruiseAltitudePlanner <- setRefClass(
  "CruiseAltitudePlanner",
  fields = list(
    trajectory = "FlightTrajectory"
  ),
  methods = list(
    initialize = function(trajectory) {
      .self$trajectory <<- trajectory
      .self$target_altitude <<- trajectory$max_altitude
    },
    adjust_altitude = function(current_time) {
      if (.self$trajectory$altitude < .self$target_altitude) {
        time_to_adjust = (.self$target_altitude - .self$trajectory$altitude) / .self$trajectory$speed
        if (current_time >= time_to_adjust) {
          .self$trajectory$update_altitude(time_to_adjust)
        }
      }
    }
  )
)

TerminationChecker <- setRefClass(
  "TerminationChecker",
  fields = list(
    trajectory = "FlightTrajectory",
    target_altitude = "numeric"
  ),
  methods = list(
    initialize = function(trajectory, target_altitude) {
      .self$trajectory <<- trajectory
      .self$target_altitude <<- target_altitude
    },
    check = function() {
      return(.self$trajectory$altitude >= .self$target_altitude)
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  max_altitude <- 30000
  speed <- 1500
  trajectory <- FlightTrajectory$new(initial_altitude, max_altitude, speed)
  planner <- CruiseAltitudePlanner$new(trajectory)
  checker <- TerminationChecker$new(trajectory, max_altitude)
  current_time <- 0
  time_step <- 10
  while (!checker$check()) {
    planner$adjust_altitude(current_time)
    current_time <<- current_time + time_step
  }
  cat("Cruise altitude reached.\n")
}

main()