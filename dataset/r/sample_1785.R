library(digest)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(
    data = "character",
    hash = "character",
    cipher = "character"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$hash <- .self$hash_data(data)
      .self$cipher <- .self$cipher_data(data)
      return(.self)
    },
    hash_data = function(data) {
      return(digest(data, algo = "sha256", serialize = FALSE))
    },
    cipher_data = function(data) {
      shifted_data <- ""
      for (char in strsplit(data, NULL)[[1]]) {
        shifted_char <- intToUtf8((utf8ToInt(char) + 3) %% 256)
        shifted_data <- paste(shifted_data, shifted_char, sep = "")
      }
      return(shifted_data)
    },
    update_data = function(new_data) {
      .self$data <- new_data
      .self$hash <- .self$hash_data(new_data)
      .self$cipher <- .self$cipher_data(new_data)
    }
  )
)

DataSimulator <- setRefClass("DataSimulator",
  fields = list(
    processor = "DataProcessor"
  ),
  methods = list(
    initialize = function(initial_data) {
      .self$processor <- DataProcessor$new(initial_data)
      return(.self)
    },
    simulate = function() {
      while (TRUE) {
        new_data <- paste(.self$processor$cipher, .self$processor$hash, sep = "")
        .self$processor$update_data(new_data)
      }
    }
  )
)

main <- function() {
  initial_data <- "seed"
  simulator <- DataSimulator$new(initial_data)
  simulator$simulate()
}

main()