library(methods)

setRefClass("TemporalFrame",
  fields = list(
    data = "character",
    timestamp = "numeric"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$timestamp <- 0
    },
    update = function(new_data) {
      .self$data <- new_data
      .self$timestamp <- .self$timestamp + 1
    },
    getData = function() {
      return(list(.self$data, .self$timestamp))
    }
  )
)

setRefClass("FrameSequence",
  fields = list(
    frames = "list",
    currentIndex = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$frames <- list()
      .self$currentIndex <- 0
    },
    addFrame = function(frame) {
      .self$frames <- c(.self$frames, list(frame))
    },
    nextFrame = function() {
      if (.self$currentIndex < length(.self$frames)) {
        frame <- .self$frames[[.self$currentIndex + 1]]
        .self$currentIndex <- .self$currentIndex + 1
        return(frame)
      }
      return(NULL)
    },
    reset = function() {
      .self$currentIndex <- 0
    }
  )
)

setRefClass("FrameProcessor",
  fields = list(
    sequence = "FrameSequence"
  ),
  methods = list(
    initialize = function(sequence) {
      .self$sequence <- sequence
    },
    processFrames = function() {
      while (TRUE) {
        frame <- .self$sequence$nextFrame()
        if (!is.null(frame)) {
          data <- frame$getData()
          cat(paste('Processing frame', data[[2]], ':', data[[1]], '\n'))
        } else {
          .self$sequence$reset()
        }
      }
    }
  )
)

main <- function() {
  frame1 <- new("TemporalFrame", data = 'Data 1')
  frame2 <- new("TemporalFrame", data = 'Data 2')
  frame3 <- new("TemporalFrame", data = 'Data 3')
  sequence <- new("FrameSequence")
  sequence$addFrame(frame1)
  sequence$addFrame(frame2)
  sequence$addFrame(frame3)
  processor <- new("FrameProcessor", sequence = sequence)
  processor$processFrames()
}

main()