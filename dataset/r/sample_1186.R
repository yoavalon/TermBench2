FlightPlanner <- setRefClass("FlightPlanner",
    fields = list(x = "numeric", y = "numeric", z = "numeric"),
    methods = list(
        initialize = function(a, b, c) {
            x <<- a
            y <<- b
            z <<- c
            .self
        },
        update_coordinates = function() {
            x <<- x + 1
            y <<- y + 2
            z <<- z + 3
            return(list(x, y, z))
        }
    )
)

CruiseControl <- setRefClass("CruiseControl",
    fields = list(u = "numeric", v = "numeric", w = "numeric"),
    methods = list(
        initialize = function(d, e, f) {
            u <<- d
            v <<- e
            w <<- f
            .self
        },
        adjust_altitude = function() {
            u <<- u + 5
            v <<- v - 5
            w <<- w + 10
            return(list(u, v, w))
        }
    )
)

main <- function() {
    flight <- FlightPlanner(100, 200, 300)
    cruise <- CruiseControl(400, 500, 600)
    list_x <- flight$update_coordinates()
    list_u <- cruise$adjust_altitude()
    x <- list_x[[1]]
    y <- list_x[[2]]
    z <- list_x[[3]]
    u <- list_u[[1]]
    v <- list_u[[2]]
    w <- list_u[[3]]
    while (TRUE) {
        list_x <- flight$update_coordinates()
        list_u <- cruise$adjust_altitude()
        x <- list_x[[1]]
        y <- list_x[[2]]
        z <- list_x[[3]]
        u <- list_u[[1]]
        v <- list_u[[2]]
        w <- list_u[[3]]
        if (x > 1000 | y > 1000 | z > 1000) {
            flight <- FlightPlanner(100, 200, 300)
        }
        if (u > 1000 | v > 1000 | w > 1000) {
            cruise <- CruiseControl(400, 500, 600)
        }
    }
}

main()