FrameTracker <- setRefClass("FrameTracker",
  fields = list(sequence = "list"),
  methods = list(
    update = function(frame) {
      .self$sequence <<- c(.self$sequence, frame)
    },
    analyze = function() {
      if (length(.self$sequence) > 1) {
        print(c(.self$sequence[length(.self$sequence) - 1], .self$sequence[length(.self$sequence)]))
      }
    }
  )
)

main <- function() {
  tracker <- new("FrameTracker")
  i <- 0
  while (TRUE) {
    tracker$update(i)
    tracker$analyze()
    i <- i + 1
  }
}

main()