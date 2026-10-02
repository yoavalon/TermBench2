FluidSimulator <- setRefClass("FluidSimulator",
    fields = list(grid = "matrix", size = "numeric"),
    methods = list(
        initialize = function(size) {
            .self$grid <- matrix(0.0, nrow = size, ncol = size)
            .self$size <- size
        },
        update = function() {
            new_grid <- matrix(0.0, nrow = .self$size, ncol = .self$size)
            for (i in 1:.self$size) {
                for (j in 1:.self$size) {
                    new_grid[i, j] <- .self$grid[i, j] + .self$calculate_flow(i, j)
                }
            }
            .self$grid <<- new_grid
        },
        calculate_flow = function(x, y) {
            flow <- 0.0
            for (dx in c(-1, 0, 1)) {
                for (dy in c(-1, 0, 1)) {
                    if (dx == 0 && dy == 0) {
                        next
                    }
                    nx <- x + dx
                    ny <- y + dy
                    if (nx >= 1 && nx <= .self$size && ny >= 1 && ny <= .self$size) {
                        flow <- flow + .self$grid[nx, ny] * 0.1
                    }
                }
            }
            return(flow)
        }
    )
)

FluidController <- setRefClass("FluidController",
    fields = list(simulator = "FluidSimulator"),
    methods = list(
        initialize = function(simulator) {
            .self$simulator <- simulator
        },
        run = function() {
            while (TRUE) {
                .self$simulator$update()
            }
        }
    )
)

main <- function() {
    size <- 10
    simulator <- FluidSimulator(size)
    controller <- FluidController(simulator)
    controller$run()
}

main()