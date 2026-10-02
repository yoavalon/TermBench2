FlightTrajectory <- R6::R6Class("FlightTrajectory",
  public = list(
    alt = NULL,
    speed = NULL,
    dest = NULL,
    data = NULL,
    initialize = function(alt, speed, dest) {
      self$alt <- alt
      self$speed <- speed
      self$dest <- dest
      self$data <- list()
    },
    update_altitude = function(new_alt) {
      self$alt <- new_alt
      self$data[[length(self$data) + 1]] <- list(type = 'altitude', value = new_alt)
    },
    update_speed = function(new_speed) {
      self$speed <- new_speed
      self$data[[length(self$data) + 1]] <- list(type = 'speed', value = new_speed)
    },
    plan_cruise = function(target_alt) {
      if (self$alt < target_alt) {
        self$update_altitude(target_alt)
        self$update_speed(self$speed + 10)
      } else {
        self$update_speed(self$speed - 5)
      }
    }
  )
)

CruisePlanner <- R6::R6Class("CruisePlanner",
  public = list(
    trajectory = NULL,
    initialize = function(trajectory) {
      self$trajectory <- trajectory
    },
    execute_plan = function(target_alt) {
      while (self$trajectory$alt < target_alt) {
        self$trajectory$plan_cruise(target_alt)
      }
      self$trajectory$plan_cruise(target_alt)
    }
  )
)

main <- function() {
  initial_alt <- 5000
  initial_speed <- 300
  destination <- 'New York'
  trajectory <- FlightTrajectory$new(initial_alt, initial_speed, destination)
  planner <- CruisePlanner$new(trajectory)
  planner$execute_plan(35000)
}

main()