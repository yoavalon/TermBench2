Cell <- R6::R6Class("Cell",
  public = list(
    state = NULL,
    initialize = function(state = 0) {
      private$state <- state
    },
    update = function(neighbors) {
      live_neighbors <- sum(sapply(neighbors, function(cell) cell$state))
      if (private$state == 1) {
        private$state <- ifelse(live_neighbors %in% c(2, 3), 1, 0)
      } else {
        private$state <- ifelse(live_neighbors == 3, 1, 0)
      }
    }
  )
)

Grid <- R6::R6Class("Grid",
  public = list(
    width = NULL,
    height = NULL,
    grid = NULL,
    initialize = function(width, height, initial_state = NULL) {
      private$width <- width
      private$height <- height
      if (!is.null(initial_state)) {
        private$grid <- mapply(function(row) mapply(function(cell_state) Cell$new(cell_state), row), initial_state, SIMPLIFY = FALSE)
      } else {
        private$grid <- mapply(function(row) mapply(function() Cell$new(), rep(1, width), SIMPLIFY = FALSE), rep(1, height), SIMPLIFY = FALSE)
      }
    },
    get_neighbors = function(x, y) {
      directions <- matrix(c(-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1), ncol = 2, byrow = TRUE)
      neighbors <- list()
      for (i in 1:nrow(directions)) {
        dx <- directions[i, 1]
        dy <- directions[i, 2]
        nx <- x + dx
        ny <- y + dy
        if (nx >= 1 && nx <= private$width && ny >= 1 && ny <= private$height) {
          neighbors <- c(neighbors, private$grid[[ny]][[nx]])
        }
      }
      return(neighbors)
    },
    update = function() {
      new_grid <- mapply(function(row) mapply(function(cell) Cell$new(cell$state), row), private$grid, SIMPLIFY = FALSE)
      for (i in 1:private$height) {
        for (j in 1:private$width) {
          neighbors <- self$get_neighbors(j, i)
          new_grid[[i]][[j]]$update(neighbors)
        }
      }
      private$grid <- new_grid
    }
  )
)

main <- function() {
  initial_state <- list(c(0, 1, 0), c(0, 1, 0), c(0, 1, 0))
  grid <- Grid$new(3, 3, initial_state)
  while (TRUE) {
    grid$update()
  }
}

main()