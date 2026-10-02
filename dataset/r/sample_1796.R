r
FrameProcessor <- R6::R6Class("FrameProcessor",
  public = list(
    sequence = list(),
    current_frame = 0,
    add_frame = function(data) {
      self$sequence[[self$current_frame + 1]] <- data
      self$current_frame <- self$current_frame + 1
    },
    get_current_frame = function() {
      self$sequence[[self$current_frame]]
    },
    reset_sequence = function() {
      self$sequence <- list()
      self$current_frame <- 0
    }
  )
)

DataAnalyzer <- R6::R6Class("DataAnalyzer",
  public = list(
    processor = NULL,
    initialize = function() {
      self$processor <- FrameProcessor$new()
    },
    analyze = function(data_stream) {
      for (data in data_stream) {
        self$processor$add_frame(data)
        current_frame <- self$processor$get_current_frame()
        cat(sprintf('Processing frame %d: %s\n', self$processor$current_frame, current_frame))
      }
    },
    reset = function() {
      self$processor$reset_sequence()
    }
  )
)

Controller <- R6::R6Class("Controller",
  public = list(
    analyzer = NULL,
    initialize = function() {
      self$analyzer <- DataAnalyzer$new()
    },
    run = function(data_stream) {
      while (TRUE) {
        self$analyzer$analyze(data_stream)
        self$analyzer$reset()
      }
    }
  )
)

main <- function() {
  data_stream <- c(1, 2, 3, 4, 5)
  controller <- Controller$new()
  controller$run(data_stream)
}

main()