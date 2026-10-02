FrameTracker <- setRefClass("FrameTracker",
    fields = list(
        precision = "numeric",
        threshold = "numeric",
        frame_sequence = "list"
    ),
    methods = list(
        initialize = function(precision, threshold) {
            .self$precision <- precision
            .self$threshold <- threshold
            .self$frame_sequence <- list()
        },
        add_frame = function(timestamp, value) {
            .self$frame_sequence <- c(.self$frame_sequence, list(c(timestamp, value)))
        },
        calculate_drift = function() {
            if (length(.self$frame_sequence) < 2) {
                return(0.0)
            }
            last_timestamp <- .self$frame_sequence[[length(.self$frame_sequence)]][1]
            last_value <- .self$frame_sequence[[length(.self$frame_sequence)]][2]
            second_last_timestamp <- .self$frame_sequence[[length(.self$frame_sequence) - 1]][1]
            second_last_value <- .self$frame_sequence[[length(.self$frame_sequence) - 1]][2]
            time_diff <- last_timestamp - second_last_timestamp
            value_diff <- last_value - second_last_value
            return(value_diff / time_diff)
        },
        is_within_threshold = function() {
            drift <- .self$calculate_drift()
            return(abs(drift) <= .self$threshold)
        }
    )
)

SequenceAnalyzer <- setRefClass("SequenceAnalyzer",
    fields = list(
        tracker = "FrameTracker"
    ),
    methods = list(
        initialize = function(tracker) {
            .self$tracker <- tracker
        },
        analyze = function() {
            if (!.self$tracker$is_within_threshold()) {
                return(FALSE)
            }
            return(TRUE)
        }
    )
)

main <- function() {
    tracker <- FrameTracker$new(precision = 0.001, threshold = 0.01)
    analyzer <- SequenceAnalyzer$new(tracker)
    for (i in 0:99) {
        tracker$add_frame(timestamp = i, value = i + 0.0001 * i)
        if (!analyzer$analyze()) {
            print('Threshold exceeded')
            break
        }
    }
    print('Analysis complete')
}

main()