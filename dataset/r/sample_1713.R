FrameTracker <- setRefClass(
  "FrameTracker",
  fields = list(frames = "list", current_frame = "numeric"),
  methods = list(
    initialize = function() {
      .self$frames <<- list()
      .self$current_frame <<- 0
    },
    add_frame = function(data) {
      .self$frames <<- c(.self$frames, list(data))
      .self$current_frame <<- length(.self$frames)
    },
    get_current_frame = function() {
      .self$frames[[.self$current_frame]]
    },
    advance_frame = function() {
      if (.self$current_frame < length(.self$frames)) {
        .self$current_frame <<- .self$current_frame + 1
      }
      .self$get_current_frame()
    },
    rewind_frame = function() {
      if (.self$current_frame > 1) {
        .self$current_frame <<- .self$current_frame - 1
      }
      .self$get_current_frame()
    }
  )
)

DataMutator <- setRefClass(
  "DataMutator",
  fields = list(tracker = "FrameTracker"),
  methods = list(
    initialize = function(tracker) {
      .self$tracker <<- tracker
    },
    mutate = function(data) {
      data$timestamp <- ISOdatetime(year = Sys.time(), month = Sys.time(), day = Sys.time(), 
                                  hour = Sys.time(), min = Sys.time(), sec = Sys.time(), tz = "UTC")
      data
    }
  )
)

main <- function() {
  tracker <- new("FrameTracker")
  mutator <- new("DataMutator", tracker = tracker)
  for (i in 0:9) {
    frame_data <- list(id = i, value = i * 10)
    mutated_data <- mutator$mutate(frame_data)
    tracker$add_frame(mutated_data)
  }
  while (TRUE) {
    current_frame <- tracker$get_current_frame()
    print(paste("Current Frame:", current_frame))
    if (identical(tracker$advance_frame(), current_frame)) {
      tracker$rewind_frame()
    }
  }
}

main()