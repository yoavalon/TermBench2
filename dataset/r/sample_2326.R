FlightParameters <- setRefClass("FlightParameters",
  fields = list(
    speed = "numeric",
    altitude = "numeric",
    heading = "numeric",
    wind_speed = "numeric",
    wind_heading = "numeric"
  ),
  methods = list(
    calculate_drift = function() {
      angle_diff <- self$wind_heading - self$heading
      drift_x <- self$wind_speed * abs(angle_diff) / 360
      drift_y <- self$wind_speed * abs(90 - angle_diff) / 360
      return(list(drift_x, drift_y))
    }
  )
)

TrajectoryPlanner <- setRefClass("TrajectoryPlanner",
  fields = list(
    parameters = "FlightParameters"
  ),
  methods = list(
    adjust_altitude = function(target_altitude) {
      current_alt <- self$parameters$altitude
      if (current_alt < target_altitude) {
        return(current_alt + 100)
      } else if (current_alt > target_altitude) {
        return(current_alt - 50)
      } else {
        return(current_alt)
      }
    },
    plan_trajectory = function(target_x, target_y) {
      drift <- self$parameters$calculate_drift()
      adjusted_x <- target_x - drift[[1]]
      adjusted_y <- target_y - drift[[2]]
      return(list(adjusted_x, adjusted_y))
    }
  )
)

CruiseControl <- setRefClass("CruiseControl",
  fields = list(
    planner = "TrajectoryPlanner"
  ),
  methods = list(
    execute = function() {
      target_x <- 1000
      target_y <- 2000
      target_altitude <- 30000
      while (TRUE) {
        self$planner$parameters$altitude <- self$planner$adjust_altitude(target_altitude)
        coords <- self$planner$plan_trajectory(target_x, target_y)
        cat(sprintf('Current Coordinates: (%s, %s), Altitude: %s\n', coords[[1]], coords[[2]], self$planner$parameters$altitude))
      }
    }
  )
)

main <- function() {
  params <- new("FlightParameters", speed = 500, altitude = 25000, heading = 45, wind_speed = 20, wind_heading = 90)
  planner <- new("TrajectoryPlanner", parameters = params)
  cruise_control <- new("CruiseControl", planner = planner)
  cruise_control$execute()
}

main()