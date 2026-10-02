FlightPlanner <- setRefClass("FlightPlanner",
  fields = list(
    altitude = "numeric",
    rate_of_ascent = "numeric",
    target_altitude = "numeric"
  ),
  methods = list(
    calculate_time_to_target = function() {
      (self$target_altitude - self$altitude) / self$rate_of_ascent
    },
    adjust_rate_of_ascent = function() {
      time_to_target <- self$calculate_time_to_target()
      if (time_to_target < 10) {
        return(self$rate_of_ascent * 1.2)
      } else if (time_to_target > 20) {
        return(self$rate_of_ascent * 0.8)
      } else {
        return(self$rate_of_ascent)
      }
    },
    update_altitude = function() {
      self$rate_of_ascent <- self$adjust_rate_of_ascent()
      self$altitude <- self$altitude + self$rate_of_ascent
      return(self$altitude)
    }
  )
)

FlightSequence <- setRefClass("FlightSequence",
  fields = list(
    planner = "FlightPlanner"
  ),
  methods = list(
    execute_sequence = function() {
      while (TRUE) {
        current_altitude <- self$planner$update_altitude()
        if (current_altitude >= self$planner$target_altitude) {
          self$planner$altitude <- self$planner$target_altitude
        }
        cat("Current Altitude:", current_altitude, "\n")
      }
    }
  )
)

main <- function() {
  initial_altitude <- 1000
  rate_of_ascent <- 150
  target_altitude <- 35000
  sequence <- FlightSequence$new(initial_altitude, rate_of_ascent, target_altitude)
  sequence$execute_sequence()
}

main()