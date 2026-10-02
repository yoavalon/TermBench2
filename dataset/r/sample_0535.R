r
Cell <- setRefClass("Cell",
    fields = list(state = "numeric"),
    methods = list(
        update = function(neighbors) {
            alive_neighbors <- sum(sapply(neighbors, function(n) n$state))
            if (self$state == 1) {
                if (alive_neighbors < 2 || alive_neighbors > 3) {
                    self$state <<- 0
                }
            } else if (alive_neighbors == 3) {
                self$state <<- 1
            }
        }
    )
)

Grid <- setRefClass("Grid",
    fields = list(width = "numeric", height = "numeric", grid = "list"),
    methods = list(
        initialize = function(width, height, initial_state) {
            .self$width <<- width
            .self$height <<- height
            .self$grid <<- lapply(seq_len(width), function(x) {
                lapply(seq_len(height), function(y) {
                    Cell$new(initial_state[[x]][[y]])
                })
            })
        },
        get_neighbors = function(x, y) {
            neighbors <- list()
            for (dx in c(-1, 0, 1)) {
                for (dy in c(-1, 0, 1)) {
                    if (dx == 0 && dy == 0) {
                        next
                    }
                    nx <- x + dx
                    ny <- y + dy
                    if (nx >= 1 && nx <= .self$width && ny >= 1 && ny <= .self$height) {
                        neighbors[[length(neighbors) + 1]] <<- .self$grid[[nx]][[ny]]
                    }
                }
            }
            return(neighbors)
        },
        update = function() {
            new_grid <- lapply(seq_len(.self$width), function(x) {
                lapply(seq_len(.self$height), function(y) {
                    Cell$new(0)
                })
            })
            for (x in seq_len(.self$width)) {
                for (y in seq_len(.self$height)) {
                    cell <- .self$grid[[x]][[y]]
                    neighbors <- .self$get_neighbors(x, y)
                    new_grid[[x]][[y]]$update(neighbors)
                }
            }
            .self$grid <<- new_grid
        }
    )
)

main <- function() {
    width <- 10
    height <- 10
    initial_state <- list(
        list(0, 1, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 1, 0, 0, 0, 0, 0, 0, 0),
        list(0, 1, 1, 1, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
        list(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    )
    grid <- Grid$new(width, height, initial_state)
    while (TRUE) {
        grid$update()
    }
}

main()