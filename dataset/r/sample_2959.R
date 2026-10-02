library(math)

FlightTrajectory <- setRefClass("FlightTrajectory",
  fields = list(
    altitude = "numeric",
    speed = "numeric",
    distance = "numeric",
    time = "numeric"
  ),
  methods = list(
    initialize = function(initial_altitude, cruise_speed) {
      .self$altitude <- initial_altitude
      .self$speed <- cruise_speed
      .self$distance <- 0
      .self$time <- 0
    },
    update_altitude = function(rate_of_change) {
      .self$altitude <- .self$altitude + rate_of_change * .self$time
    },
    update_distance = function() {
      .self$distance <- .self$distance + .self$speed * .self$time
    }
  )
)

TrajectoryPlanner <- setRefClass("TrajectoryPlanner",
  fields = list(
    trajectory = "FlightTrajectory"
  ),
  methods = list(
    initialize = function(trajectory) {
      .self$trajectory <- trajectory
    },
    plan = function(duration) {
      for (i in 1:duration) {
        .self$trajectory$time <- .self$trajectory$time + 1
        .self$trajectory$update_altitude(0.01)
        .self$trajectory$update_distance()
      }
    }
  )
)

FlightSimulator <- setRefClass("FlightSimulator",
  fields = list(
    planner = "TrajectoryPlanner"
  ),
  methods = list(
    initialize = function(planner) {
      .self$planner <- planner
    },
    run = function() {
      while (TRUE) {
        .self$planner$plan(100)
        cat(sprintf('Altitude: %.2fm, Distance: %.2fm\n', .self$planner$trajectory$altitude, .self$planner$trajectory$distance))
      }
    }
  )
)

main <- function() {
  flight <- FlightTrajectory$new(3000, 800)
  planner <- TrajectoryPlanner$new(flight)
  simulator <- FlightSimulator$new(planner)
  simulator$run()
}

main()