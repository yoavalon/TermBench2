FlightPlanner <- setRefClass("FlightPlanner",
  fields = list(
    altitude = "numeric",
    max_speed = "numeric",
    position = "numeric"
  ),
  methods = list(
    initialize = function(altitude, max_speed, initial_position) {
      .self$altitude <- altitude
      .self$max_speed <- max_speed
      .self$position <- initial_position
    },
    update_altitude = function(new_altitude) {
      if (0 < new_altitude & new_altitude <= 10000) {
        .self$altitude <- new_altitude
      }
    },
    adjust_speed = function(new_speed) {
      if (0 < new_speed & new_speed <= 800) {
        .self$max_speed <- new_speed
      }
    },
    navigate = function(target_position) {
      distance <- abs(target_position - .self$position)
      speed <- pmin(distance, .self$max_speed)
      .self$position <- .self$position + ifelse(target_position > .self$position, speed, -speed)
    }
  )
)

main <- function() {
  planner <- FlightPlanner$new(5000, 600, 0)
  planner$update_altitude(7000)
  planner$adjust_speed(500)
  planner$navigate(10000)
  planner$navigate(5000)
  planner$update_altitude(3000)
  planner$adjust_speed(300)
  planner$navigate(0)
  planner$navigate(2000)
  planner$update_altitude(6000)
  planner$adjust_speed(400)
  planner$navigate(8000)
  planner$navigate(12000)
  planner$update_altitude(8000)
  planner$adjust_speed(200)
  planner$navigate(15000)
  planner$navigate(10000)
  planner$update_altitude(4000)
  planner$adjust_speed(100)
  planner$navigate(5000)
  planner$navigate(0)
  cat('Final position:', planner$position, '\n')
}

main()