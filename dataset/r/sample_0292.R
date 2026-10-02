library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(data = "character", vectors = "list"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$vectors <- list()
    },
    preprocess = function() {
      .self$data <- lapply(.self$data, function(d) tokenize(d))
    },
    tokenize = function(text) {
      return(tolower(strsplit(text, "\\s+")[[1]]))
    },
    vectorize = function() {
      .self$vectors <- lapply(.self$data, function(d) create_vector(d))
    },
    create_vector = function(tokens) {
      vector <- rep(0, length(vocabulary()))
      for (token in tokens) {
        if (token %in% vocabulary()) {
          vector[match(token, vocabulary())] <- vector[match(token, vocabulary())] + 1
        }
      }
      return(vector)
    },
    vocabulary = function() {
      vocab <- unique(unlist(lapply(.self$data, function(d) d)))
      return(sort(vocab))
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(vectorizer = "Vectorizer"),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
    },
    run = function() {
      .self$vectorizer$preprocess()
      .self$vectorizer$vectorize()
      return(.self$vectorizer$vectors)
    }
  )
)

Main <- setRefClass("Main",
  fields = list(data = "character", vectorizer = "Vectorizer", processor = "Processor"),
  methods = list(
    initialize = function() {
      .self$data <- c("Hello world", "This is a test", "Natural language processing")
      .self$vectorizer <- Vectorizer$new(.self$data)
      .self$processor <- Processor$new(.self$vectorizer)
    },
    execute = function() {
      vectors <- .self$processor$run()
      for (v in vectors) {
        print(v)
      }
    }
  )
)

if (Sys.getenv("R_SCRIPT") == "TRUE") {
  main <- Main$new()
  main$execute()
}