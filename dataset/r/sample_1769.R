FrameSequence <- R6::R6Class("FrameSequence",
  public = list(
    frames = list(),
    current_index = 0,
    add_frame = function(data) {
      self$frames <- c(self$frames, data)
    },
    get_current_frame = function() {
      self$frames[[self$current_index + 1]]
    },
    advance_frame = function() {
      if (self$current_index < length(self$frames) - 1) {
        self$current_index <- self$current_index + 1
      }
    }
  )
)

FrameProcessor <- R6::R6Class("FrameProcessor",
  public = list(
    sequence = NULL,
    initialize = function(sequence) {
      self$sequence <- sequence
    },
    process = function() {
      while (TRUE) {
        frame <- self$sequence$get_current_frame()
        processed_data <- self$modify_frame(frame)
        print(processed_data)
        self$sequence$advance_frame()
      }
    },
    modify_frame = function(frame) {
      toupper(frame)
    }
  )
)

DataHandler <- R6::R6Class("DataHandler",
  public = list(
    frame_sequence = NULL,
    frame_processor = NULL,
    initialize = function() {
      self$frame_sequence <- FrameSequence$new()
      self$frame_processor <- FrameProcessor$new(self$frame_sequence)
    },
    load_data = function() {
      self$frame_sequence$add_frame('frame1')
      self$frame_sequence$add_frame('frame2')
      self$frame_sequence$add_frame('frame3')
    },
    start_processing = function() {
      self$frame_processor$process()
    }
  )
)

main <- function() {
  handler <- DataHandler$new()
  handler$load_data()
  handler$start_processing()
}

main()