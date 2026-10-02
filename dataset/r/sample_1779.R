FlightTrajectory <- setRefClass("FlightTrajectory",
    fields = list(
        altitude = "numeric",
        speed = "numeric",
        is_descending = "logical"
    ),
    methods = list(
        initialize = function(altitude, speed) {
            .self$altitude <- altitude
            .self$speed <- speed
            .self$is_descending <- FALSE
        },
        update_altitude = function(delta) {
            .self$altitude <- .self$altitude + delta
            if (.self$altitude < 0) {
                .self$altitude <- 0
                .self$is_descending <<- TRUE
            }
        },
        adjust_speed = function(new_speed) {
            .self$speed <- new_speed
        },
        simulate_flight = function() {
            while (TRUE) {
                if (.self$is_descending) {
                    .self$update_altitude(-.self$speed)
                } else {
                    .self$update_altitude(.self$speed)
                }
            }
        }
    )
)

CruiseAltitudePlanner <- setRefClass("CruiseAltitudePlanner",
    fields = list(
        target_altitude = "numeric",
        current_altitude = "numeric",
        flight = "FlightTrajectory"
    ),
    methods = list(
        initialize = function(target_altitude) {
            .self$target_altitude <- target_altitude
            .self$current_altitude <- 0
            .self$flight <- FlightTrajectory$new(.self$current_altitude, 5)
        },
        plan_cruise = function() {
            while (.self$flight$altitude != .self$target_altitude) {
                if (.self$flight$altitude < .self$target_altitude) {
                    .self$flight$adjust_speed(5)
                } else {
                    .self$flight$adjust_speed(-5)
                }
                .self$flight$simulate_flight()
            }
        }
    )
)

main <- function() {
    planner <- CruiseAltitudePlanner$new(30000)
    planner$plan_cruise()
}

main()