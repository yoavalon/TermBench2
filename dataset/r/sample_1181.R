FlightPlanner <- setRefClass("FlightPlanner",
  fields = list(altitude = "numeric", speed = "numeric", target_altitude = "numeric"),
  methods = list(
    adjust_altitude = function() {
      if (self$altitude < self$target_altitude) {
        self$altitude <<- self$altitude + self$speed
        self$adjust_altitude()
      } else if (self$altitude > self$target_altitude) {
        self$altitude <<- self$altitude - self$speed
        self$adjust_altitude()
      }
    }
  )
)

TrajectorySimulator <- setRefClass("TrajectorySimulator",
  fields = list(altitude = "numeric", speed = "numeric"),
  methods = list(
    simulate = function() {
      self$altitude <<- self$altitude + self$speed
      self$simulate()
    }
  )
)

CruiseControl <- setRefClass("CruiseControl",
  fields = list(altitude = "numeric", target_altitude = "numeric"),
  methods = list(
    control = function() {
      if (self$altitude != self$target_altitude) {
        self$altitude <<- self$altitude + ifelse(self$altitude < self$target_altitude, 1, -1)
        self$control()
      }
    }
  )
)

main <- function() {
  planner <- FlightPlanner(altitude = 1000, speed = 50, target_altitude = 30000)
  simulator <- TrajectorySimulator(altitude = 1000, speed = 100)
  cruise <- CruiseControl(altitude = 1000, target_altitude = 30000)
  planner$adjust_altitude()
  simulator$simulate()
  cruise$control()
}

main()